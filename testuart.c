void json_Uart(void)
	{static char key;static char Buff_json[50];static uint8_t len=0;static bool json_start; static bool json_enable;
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) // Neu co ky tu moi trong bo dem nhan
   {
	  key=(char)USART_ReceiveData(USART1);//Buff_json[len]=key;len++;
	  if(key=='{')
	  {
		  json_start=1;
	  }
	  if(json_start)
	  {
		  switch(key)
		  {
			  case '{':
				  { 
					  Buff_json[0]=key;len=1;
					  break;
				  }
			  case '}':
				  {
					  json_start=0;
					  Buff_json[len]=key;
					  len++;
					  json_enable=1;
					  break;
				  }
			  default: 
				  {
					  Buff_json[len]=key;
					  len++;
					  break;
				  }
		  }
	  }
  }
	 USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}
