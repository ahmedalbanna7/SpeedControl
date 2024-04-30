/*
 * password.c
 *
 * Created: 4/27/2020 1:22:12 AM
 *  Author: ahmed
 */ 

 #include <password.h>

 void int2_Event(void);

 void initpass (void)
 {
	GPIO_DirectionSet(GPIOD,PIN3,OUTPUT);
	GPIO_DirectionSet(GPIOD,PIN4,OUTPUT);
	 unsigned char i = 0;							//Just a counter
	 LCD_init();										//Initialize LCD
	 GPIO_DirectionSet(GPIOB,PIN2,INPUT_PULLUP);				//PD0 is an input pin (pull-up)
	 Ext_InterruptEnable(Interrupt0,FallingMode);		//Enable INT0, FALLING_EDGE
		GLOBAL_INETERRUPT_ENABLE()
	 eeprom_write(NUM_OF_TRIALS_ADDR,0);
	
#if SETUP
	 eeprom_write(1,4);
	 eeprom_write(2,'1');
	 eeprom_write(3,'2');
	 eeprom_write(4,'3');
 	 eeprom_write(5,'4');

	  eeprom_write(27,'0');
	  eeprom_write(28,'0');
	  eeprom_write(29,'0');
	  eeprom_write(30,'0');
	  eeprom_write(31,'0');
	  eeprom_write(32,'0');
	  eeprom_write(33,'0');
	  eeprom_write(34,'0');
	  eeprom_write(35,'0');
	  eeprom_write(36,'0');
	  eeprom_write(37,'0');


#endif
 }

 void sign_up (void)
 {
	 unsigned char desired_password_1[11] = {0};		//The first entered password is saved here
	 unsigned char desired_password_2[11] = {0};		//The second entered password is saved here
	 unsigned char length_1 = 0;						//Length of first entered password
	 unsigned char length_2 = 0;						//Length of second entered password

	LCD_Clear();
	LCD_Select_RowCol(0,1);
	 LCD_DisplayString("Your new Password: ");
	LCD_Select_RowCol(1,1);
	 length_1 = get_password(desired_password_1);
	 
	LCD_Clear();
	LCD_Select_RowCol(0,1);
	 LCD_DisplayString("Re-enter Password: ");
	 LCD_Select_RowCol(1,2);
	 length_2 = get_password(desired_password_2);
	 
	 
	 if(compare(desired_password_1,desired_password_2,length_1,length_2))
	 {
		 unsigned char i = 0;		//Just a counter variable
		 
		 //Save the length of the password in EEPROM (Location = 0x0001)
		 eeprom_write(0x0001,length_1);
		 
		 for(i = 0; i < length_1; i++)
		 {
			 //Save the password in EEPROM (In location from 2 to 12)
			 eeprom_write(i+2,desired_password_1[i]);
		 }
		 GLOBAL_INETERRUPT_ENABLE();
		 
		 //Successful operation
		 LCD_Clear();
		 LCD_DisplayStringrowcol("Your password is saved",1,0);		 
		 _delay_ms(1000);
	 }
	 
	 else
	 {
		 //Failed operation, try again
		 LCD_Clear();
		 LCD_DisplayStringrowcol("Failed operation",0,0);
		 LCD_DisplayStringrowcol("please, Try again",1,0);
		 _delay_ms(1000);
		 sign_up();
	 }
 }

 unsigned char compare(unsigned char* pass1, unsigned char* pass2, unsigned char len1, unsigned char len2)
{
	unsigned char i = 0;
	if(len1 != len2)
	{
		
		#if DEBUG
		LCD_Clear()
		LCD_DisplayStringrowcol("Wrong ",1,1);
		_delay_ms(1000);
		#endif
		return 0;
	}
	
	else
	{
		for(i = 0; i < len1; i++)
		{
			if(pass1[i] != pass2[i])
			{
				#if DEBUG
				LCD_Clear();
				LCD_DisplayStringrowcol("pass1=",0,0);
				LCD_DisplayStringrowcol(itoa((int)pass1[i],(char*)str,10),0,7);
				LCD_DisplayStringrowcol("pass2=",1,0);
				LCD_DisplayStringrowcol(itoa((int)pass2[i],(char*)str,10),1,7);
				_delay_ms(500);
				#endif
				return 0;
			}
			else
			{
				#if DEBUG
				LCD_Clear();
				LCD_DisplayStringrowcol("pass1=",0,0);
				LCD_DisplayStringrowcol(itoa((int)pass1[i],str,10),0,7);
				LCD_DisplayStringrowcol("pass2 = ",1,0);
				LCD_DisplayStringrowcol(itoa((int)pass2[i],str,10),1,7);
				_delay_ms(2000);
				#endif
				continue;			//No need for it, just to make the code readable
			}
		}
		return 1;
	}

}

unsigned char get_password(unsigned char* pass)
{
	int cnt = 0;
	unsigned char key = 0;
	unsigned i = 0 ;
	LCD_Select_RowCol(1,1);
	for(cnt = 0; cnt <= 10 ; )
	{
		key = keyfind();
		
		if(key == '+')
		{
			break;
		}
		
		
		else if(key == '*' && cnt <= 0)
		{
			cnt = 0;
		}
		else if(cnt != 10)
		{
			pass[cnt++] = key;
			LCD_Select_RowCol(1,i);
			LCD_DisplayString("*");
			i++;
		}
	}

	LCD_Clear();	
	return cnt;
}
 
 void log_in (void)
 {
	 unsigned char entered_password[11] = {0};				//The entered password is saved here
	 unsigned char length = 0;								//Length of entered password
	 
	 LCD_Clear();
	 LCD_DisplayStringrowcol("Enter your password: ",0,0);
	 LCD_Select_RowCol(1,2);
	 length = get_password(entered_password);
	 
	 if(check_password(length, entered_password))
	 {
		open_the_door();
	 }
	 else
	 {
		 try_again();
	 }
 }

 unsigned char check_password(unsigned char len, unsigned char* password)
 {
	 unsigned char i = 0;				//Just a counter variable
	 
	 if(eeprom_read(0x0001) != len)		//Length is stored in EEPROM location 0x0001
	 {
		 return 0;
	 }
	 else
	 {
		 for(i = 0; i < len; i++)
		 {
			 if(password[i] != eeprom_read(i+2))		//Password is stored in EEPROM from location 2 to 12
			 {
				LCD_Clear()	;
				 LCD_DisplayStringrowcol("break",1,6);
				 _delay_ms(1000);
				 return 0;
			 }
		 }
		 return 1;
	 }
 }

 void change_password(void)
 {
	 unsigned char old_password[10] = {0};		//Old password is stored here
	 unsigned char length = 0;					//length of old password is stored here
	 
	 LCD_Clear();
	 LCD_DisplayStringrowcol("Enter old password:",0,1);
	 LCD_Select_RowCol(1,2);
	 length = get_password(old_password);
	 if (check_password(length, old_password))
	 {
		 sign_up();
	 }
	 else
	 {
		 LCD_Clear();
		 LCD_DisplayStringrowcol("your password not found",0,1);
		 change_password();
	 }
 }

 void int2_Event(void)
 {
	 close_the_door();
 }
 
 void welcome_message (void)
 {
	 LCD_Clear();
	 LCD_DisplayStringrowcol("Password-lock door",0,0);
	 LCD_DisplayStringrowcol("      Welcome!",1,0);
 }

 void choose_list (void)
 {
	 LCD_Clear();
	 LCD_DisplayStringrowcol("(1)Log-in",0,0);
	 LCD_DisplayStringrowcol("(2)sign-up",1,0);
 }

 choose_listsecond()
 {
  LCD_Clear();
  LCD_DisplayStringrowcol("(1)Log-in",0,0);
  LCD_DisplayStringrowcol("(2)Change Password",1,0);
 if (keyfind() == '1')
 {
	log_in();
 }
 else if (keyfind() == '2')
 {
 change_password();
 }
 else
 {
 LCD_DisplayString("foooo");
 }
 }
 	void try_again (void)
 	{
	 	static unsigned char number_of_trials = 0;
	 	number_of_trials = eeprom_read(NUM_OF_TRIALS_ADDR);
 		eeprom_write(NUM_OF_TRIALS_ADDR,++number_of_trials);			//This variable is stored in EEPROM location number 25
 	
 	if(eeprom_read(NUM_OF_TRIALS_ADDR) == 3 || eeprom_read(NUM_OF_TRIALS_ADDR) == 6)
 	{
	 	unsigned char i = 0;
	 	LCD_Clear();
	 	LCD_DisplayStringrowcol("Wrong password",0,2);
	 	LCD_DisplayStringrowcol("Try again in    Sec",1,0);
	 	for(i = 59; i > 0; i--)
	 	{
		 	LCD_Select_RowCol(1,14);
		 	itoa((int)i, str, 10);
		 	LCD_DisplayString(str);
		 	_delay_ms(100);
	 	}
	 	log_in();
 	}
 	
 	 else if (eeprom_read(NUM_OF_TRIALS_ADDR) >= 9)
 	{
	 	eeprom_write(26,0xFF);
	 	unsigned char chk = 0;
	 	do
	 	{
		 	chk = get_puk_code();
		 	
	 	} while (!chk);
	 	
	 	LCD_Clear();
	 	LCD_DisplayStringrowcol("Successful operation",0,3);
	 	eeprom_write(NUM_OF_TRIALS_ADDR,0);
	 	_delay_ms(1000);
	 	sign_up();
 	}
 	
 	else
 	{
	 	LCD_Clear();
	 	LCD_DisplayStringrowcol("Wrong password",0,1);
	 	LCD_DisplayStringrowcol("Plz, try again",1,1);
	 	_delay_ms(1000);
	 	log_in();
 	}
 }

 /*************************************************************************************************************/

 //This function checks if the user enters the puk code correctly or not

 unsigned char get_puk_code(void)
 {
	 unsigned char i = 0;				//Just a counter variable
	 unsigned char puk_code[10] = {0};
	 unsigned char length = 0;
	 
	 LCD_Clear();
	 LCD_DisplayStringrowcol(" The door is closed ",0,0);
	 LCD_DisplayStringrowcol("    permanently",1,0);
	 _delay_ms(1000);
	 
	 LCD_Clear();
	 LCD_DisplayStringrowcol("Enter PUK code: ",0,0);
	 LCD_Select_RowCol(1,2);
	 length = get_password(puk_code);
	 
	 if(length != 10)		//PUK code is 10 numbers + the ending '*' which acts as an enter.
	 {
		 LCD_Clear();
		 LCD_DisplayString(itoa((int)length,str,10));
		 _delay_ms(1000);
		 return 0;
	 }
	 else
	 {
		 for(i = 0; i < 10; i++)
		 {
			 if(puk_code[i] != eeprom_read(i+27))		//Password is stored in EEPROM from location 27 to 37
			 {
				 return 0;
			 }
		 }
		 return 1;
	 }
 }

 /*************************************************************************************************************/