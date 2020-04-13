#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main (){
  FILE *pFile;
  int flag,i,j, err, n;
  char palavra[100];
  pFile = fopen ("teste.txt","r");
  
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    while (!feof(pFile)) {
    	fgets(palavra,sizeof(palavra),pFile);
    	flag = 0;
    	err=0;
    	i=0;
    	
    	if(palavra){
    		while(i<strlen(palavra)-1){
    			if(palavra[i]=='0'){
    				if(flag==1){
    					if(palavra[i-1]=='0'){
    						err=1;
    						break;
						}
					}
    			}
    			
				if(palavra[i]=='1'){
					if(palavra[i+1]=='1'){
						if(palavra[i+2]=='0'){
							flag=1;
							i++;;
						}else{
							err=1;
    						break;
						}
					}else{
						
						for(j=i+1;j<strlen(palavra)-1;j++){
							i=j;
							if(palavra[j]=='1'){
								err=1;
								
    							break;
							}
						}
					}
				}
				
				if(palavra[i]=='e' || palavra[i]==' '){
					err=1;
				}
				i++;
			}
		}
		
		if(err==1 || palavra==NULL){
			printf("Cadeia: '");
			for(n=0;n<strlen(palavra)-1;n++)
				printf("%c",palavra[n]);
			printf("' rejeitada\n");
		}else{
			printf("Cadeia: '");
			for(n=0;n<strlen(palavra)-1;n++)
				printf("%c",palavra[n]);
			printf("' valida\n");
		}
    }
   
    fclose (pFile);
  }
  return 0;
}
