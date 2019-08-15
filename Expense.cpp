//DAILY EXPENDITURE
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void password();
void option1();
void option2();
void option3();
void option4();
void option5();
void option6();
void process();
int summation(int month);

char pw[25],ch;
int option,amount,date,month,amt[15][50],day[15][50];

int main()
{
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=31;j++)
        {
                amt[i][j]=0;
                day[i][j]=j;        
        }        
    }

    printf("\t\t\t *****************************\n");   
    printf("\t\t\t|     Expenses Manager        |\n");
    printf("\t\t\t|           |()|            |\n");
    printf("\t\t\t|With C file system interaction |\n");
    printf("\t\t\t *****************************\n\n");
    
    password();
    char names[]="sonuyadav";//password
    while(1)
    {
             int p=0;             
             if(strlen(pw)==strlen(names))
             {
                          for(int i=0;i<strlen(pw);i++)
                          {                                  
                                  if(names[i]!=pw[i])
                                  { //character unmatch
                                                    p=1;
                                                    break; 
                                  }
                          }
             }
             else
             { //lengths diff, password incorrect
                   p=1;
             }                                 
             if(p==1)
             {
                    printf("\n...The Password - %s - Is Wrong...Try Again.....\n\n",pw);
                    password();   
             } 
             if(p==0)
             {
                         printf("\n\t\t\t...Welcome Bundz...\n\n");
                         break;
             }                  
    } 
    printf("\t\t\t1.Add daily expenditure.\n");
    printf("\t\t\t2.Display daily expenditure.\n");       
    printf("\t\t\t3.Change records.\n");
    printf("\t\t\t4.Display summary of monthly expenditure.\n");
    printf("\t\t\t5.Exit.\n\n"); 
     
    process();  
    getch();
    return 0;
    }
    
void password()
{     
  int i;  
  puts("Please Enter Password :");//printf("Please Enter password");
  while(1)
  {
        if(i<0)        
                i=0;        
        ch=getch();//to prevent the password printing on screen
        if(ch==13)
                break; /*13 is ASCII value of ENTER*/
        if(ch==8) /*ASCII value of BACKSPACE*/
        {
                putch('\b');                   
                --i;
                continue;
        }
        pw[i]=ch;
        i++;
        ch='*';
        printf("%c",ch);//putch(ch);
  }
 pw[i]='\0';
//printf("\n\n%s",pw);
}       

void process()
{     
     printf("\nEnter Your Choice: ");
     scanf("%d",&option);
     if(option==1)
     {
                             option1();
                             option6();
                             process();  
     }   
     else if(option==2)
     {
                              option2(); 
                              option6();  
                              process();                                                                                      
     }
     else if(option==3)
     {
                              option3(); 
                              option6();
                              process();                                                                                                      
     }
     else if(option==4)
     {
                              option4(); 
                              option6();
                              process();                                                                                                      
     }                  
     else if(option==5)
     { 
                              option5();
     }                 
     else
     {
                              printf("ARE U CRAZY??? Plz enter a choice from 1-4:\n ");
                              process();  
     }
}
void option1()
{
     int i=1,tot=0;
     
     //A file represents a sequence of bytes on the disk where a group of related data is stored. 
	 //File is created for permanent storage of data. It is a ready made structure.
     FILE *fp;
     printf("\n-( ADD DAILY EXPENDITURE )-\n_____________________________________\n\nEnter month number: ");
     scanf("%d",&month); 
     while(month>12 || month<0)
     {
                    if(month<0)
                    {
                                printf("Month number can't be negative.\nEnter month: ");
                                scanf("%d",&month);
                    }
                    if(month>12)
                    {
                                printf("There are only 12 months.\nEnter month: ");
                                scanf("%d",&month);
                    }            
     }
     
     //r – Opens a file in read mode and sets pointer to the first character in the file. It returns null if file does not exist.
	//w – Opens a file in write mode. It returns null if file could not be opened. If file exists, data are overwritten.
	//a – Opens a file in append mode.  It returns null if file couldn’t be opened(here we use append but not write as write overwrites)
     
	 //RECORD THE SCANNED DATA TOTHE FILE OF RELEVANT MONTH
     if(month==1)
     {
           fp=fopen("january.txt","a");
     }
     if(month==2)
     {
           fp=fopen("february.txt","a");
     }
     if(month==3)
     {
           fp=fopen("march.txt","a");
     }
     if(month==4)
     {
           fp=fopen("april.txt","a");
     }
     if(month==5)
     {
           fp=fopen("may.txt","a");
     }
     if(month==6)
     {
           fp=fopen("june.txt","a");
     }
     if(month==7)
     {
           fp=fopen("july.txt","a");
     }
     if(month==8)
     {
           fp=fopen("august.txt","a");
     }
     if(month==9)
     {
           fp=fopen("september.txt","a");
     }
     if(month==10)
     {
           fp=fopen("october.txt","a");
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","a");
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","a");
     }                  
     
	 
//fopen()	create a new file or open a existing file
//fclose()	closes a file
//getc()	reads a single character from a file
//putc()	writes a character to a file
//fscanf()	reads a set of data from a file(here we read multiple charactered integer)
//fprintf()	writes a set of data to a file
	 
	 
	 //this IF for writing upto: date - amount Updated Expenditure :            
     if(fp!=NULL)
     {                                  
                  printf("Enter date:just (dd)");
                  scanf("%d",&date); 
                  printf("Enter amount: ");
                  scanf("%d",&amount);              
                  fprintf(fp,"%d - %d ",date,amount);
                  fprintf(fp,"Updated Expenditure :");                  
     }
     fclose(fp);   
      
       //this IF for writing total expenditure value after: "date - amount Updated Expenditure :"   
      //READ DATA FROM THE RECORDED FILE OF RELEVANT MONTH TO OBTAIN UPDATED TOTAL         
     if(month==1)
     {
           fp=fopen("january.txt","r");
     }
     if(month==2)
     {
           fp=fopen("february.txt","r");
     }
     if(month==3)
     {
           fp=fopen("march.txt","r");
     }
     if(month==4)
     {
           fp=fopen("april.txt","r");
     }
     if(month==5)
     {
           fp=fopen("may.txt","r");
     }
     if(month==6)
     {
           fp=fopen("june.txt","r");
     }
     if(month==7)
     {
           fp=fopen("july.txt","r");
     }
     if(month==8)
     {
           fp=fopen("august.txt","r");
     }
     if(month==9)
     {
           fp=fopen("september.txt","r");
     }
     if(month==10)
     {
           fp=fopen("october.txt","r");
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","r");
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","r");
     }                              
     
	 
	 //storing all expenses till date in array amt             
     if(fp!=NULL)
     {                  
            char c='p'; //to enter to the next loop
            while(c!=EOF)
            {                       //getc(fp) reads a single character from file whom fp is pointing
            //fp file pointer mover one character ahead after is is read by getc()
                     while(c!='U')
                     {//updated expenditure
                                 fscanf(fp,"%d",&day[month][i]);
                                 getc(fp);//" "                                 
                                 getc(fp);//"-"                              
                                 getc(fp);//" "                                
                                 fscanf(fp,"%d",&amt[month][i]);                                                         
                                 getc(fp);//" " 
                                 c=getc(fp);//"U" 
                     }
                     while(c!=':')
                     {
                                      c=getc(fp);//pdated Expenditure :
                     }
                     c=getc(fp);
                     if(c!=EOF)
                     {
                               while(c!='\n')
                               {
                                            c=getc(fp);
                               }
                     }              
                     i++;
            }        
      }
      fclose(fp); 
      
	  
	  //putting summation of total till date at the end of  : "date - amount Updated Expenditure :"       
      for(int j=1;j<i;j++)
      {
              tot+=amt[month][j];
      }         
      //write total to the end of file after 'Updated expense:' as we already wrote text till ':'
      //'append' returns pointer after the last character i.e. ':'
	   
      //WRITE THE NEW UPDATED TOTAL TO THE FILE OF MONTH    
     if(month==1)
     {
           fp=fopen("january.txt","a");
     }
     if(month==2)
     {
           fp=fopen("february.txt","a");
     }
     if(month==3)
     {
           fp=fopen("march.txt","a");
     }
     if(month==4)
     {
           fp=fopen("april.txt","a");
     }
     if(month==5)
     {
           fp=fopen("may.txt","a");
     }
     if(month==6)
     {
           fp=fopen("june.txt","a");
     }
     if(month==7)
     {
           fp=fopen("july.txt","a");
     }
     if(month==8)
     {
           fp=fopen("august.txt","a");
     }
     if(month==9)
     {
           fp=fopen("september.txt","a");
     }
     if(month==10)
     {
           fp=fopen("october.txt","a");
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","a");
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","a");
     }                      
    fprintf(fp,"%d\n",tot); //changing line(\n) after printing total after ':'     
    fclose(fp); 
    printf("\nWELL Ur Details Are Succesfully Recorded!!!");                                   
 }
  
 //daily expenditure of a month 
 void option2()
 {
     int i=1,x=0,tot=0;
     char c;
     printf("\n-( DISPLAY DAILY EXPENDITURE )-\n_____________________________________\n\nEnter month number: ");
     scanf("%d",&month); 
     while(month>12 || month<0)
     {
                    if(month<0)
                    {
                                printf("Month number can't be negative.\nEnter month: ");
                                scanf("%d",&month);
                    }
                    if(month>12)
                    {
                                printf("There are only 12 months.\nEnter month: ");
                                scanf("%d",&month);
                    }            
     }
     FILE *fp;
     if(month==1)
     {
           fp=fopen("january.txt","r");
           printf("\n...Month:January\n\n");
           c=getc(fp);//to check whether it's an empty file
           if(c==EOF)
           {        //x is assigned 0 if file is not empty
                      x=1;//assign 1 for x if it is still an empty file 
           }
           fclose(fp);
           fp=fopen("january.txt","r"); //have to reopen the file in order to read from the begining (if its not empty, then we wil read it as per option 2())           
     }
     if(month==2)
     {
           fp=fopen("february.txt","r");
           printf("\n...Month:February\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("february.txt","r");    
     }
     if(month==3)
     {
           fp=fopen("march.txt","r");
           printf("\n...Month:March\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("march.txt","r");    
     }
     if(month==4)
     {
           fp=fopen("april.txt","r");
           printf("\n...Month:April\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("april.txt","r");    
     }
     if(month==5)
     {
           fp=fopen("may.txt","r");
           printf("\n...Month:May\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("may.txt","r");    
     }
     if(month==6)
     {
           fp=fopen("june.txt","r");
           printf("\n...Month:June\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("june.txt","r");    
     }
     if(month==7)
     {
           fp=fopen("july.txt","r");
           printf("\n...Month:July\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("july.txt","r");    
     }
     if(month==8)
     {
           fp=fopen("august.txt","r");
           printf("\n...Month:August\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("august.txt","r");    
     }
     if(month==9)
     {
           fp=fopen("september.txt","r");
           printf("\n...Month:September\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("september.txt","r");    
     }
     if(month==10)
     {
           fp=fopen("october.txt","r");
           printf("\n...Month:October\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("october.txt","r");    
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","r");
           printf("\n...Month:Novembr\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("novembr.txt","r");    
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","r");
           printf("\n...Month:Decembr\n\n");
           c=getc(fp);
           if(c==EOF)
           {
                      x=1; 
           }
           fclose(fp);
           fp=fopen("decembr.txt","r");    
     }                               
     if(x==0)
     { //if it is not an empty file            
           if(fp!=NULL)
           {        
                 while(1)
                 {                         
                                 fscanf(fp,"%d",&day[month][i]);                                                                                   
                                 getc(fp);//" "                                 
                                 getc(fp);//"-"                                
                                 c=getc(fp);//" "                                 
                                 fscanf(fp,"%d",&amt[month][i]);                                                           
                                 while(c!='\n')
                                 {
                                      c=getc(fp);
                                      if(c==EOF)
                                      {
                                                 break;
                                      }
                                  } 
                                  if(c==EOF)
                                  {
                                             break;
                                  }                                
                                  i++;
                 }                    
            }           
            fclose(fp); 
           
            for(int j=1;j<i;j++)
            {
                 tot+=amt[month][j];//obtain total expenditure
            }
            printf("Date  Expense\t\t\tDate  Expense\t\t\tDate  Expense\n\n");        
            for(int l=1;l<i;l++)
            {        
                
                  printf("%d      %d\t\t\t",day[month][l],amt[month][l]);
                  if(l%3==0)         
                        printf("\n"); //line change when 3 date-expense pairs are written in a row 
            }        
            printf("\n\nTotal Expenditure : Rs.%d.00",tot);         
     }
     if(x==1)
     {//If the file is empty
            printf("Expenditure is Rs.0.00");
     }                                   
}
       
void option3()
{
     FILE *fp;
     int tot=0,temp,max=0;
     char c;
     printf("\n-( CHANGE RECORDS )-\n_____________________________________\n\n");
     printf("Which month's record do you want to change:  ");
     scanf("%d",&month);
     while(month>12 || month<0)
     {
                    if(month<0)
                    {
                                printf("Month number can't be negative. Enter again: ");
                                scanf("%d",&month);
                    }
                    if(month>12)
                    {
                                printf("There are only 12 months.\nEnter month: ");
                                scanf("%d",&month);
                    }            
     }
     fflush(stdin);
     printf("Which date:  ");
     scanf("%d",&date);
     fflush(stdin);
     printf("What is the new expense:  ");
     scanf("%d",&amount); 
     fflush(stdin);   
	//we ll store all the data of this month file in 'day' and 'amt' array, then replace the given data data in those arrays
	//then write the file again with new data
      //obtain recorded data to write the file again   
     if(month==1)
     {
           fp=fopen("january.txt","r");
     }
     if(month==2)
     {
           fp=fopen("february.txt","r");
     }
     if(month==3)
     {
           fp=fopen("march.txt","r");
     }
     if(month==4)
     {
           fp=fopen("april.txt","r");
     }
     if(month==5)
     {
           fp=fopen("may.txt","r");
     }
     if(month==6)
     {
           fp=fopen("june.txt","r");
     }
     if(month==7)
     {
           fp=fopen("july.txt","r");
     }
     if(month==8)
     {
           fp=fopen("august.txt","r");
     }
     if(month==9)
     {
           fp=fopen("september.txt","r");
     }
     if(month==10)
     {
           fp=fopen("october.txt","r");
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","r");
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","r");
     } 
     for(int i=1;i<=12;i++)
     {
        for(int j=1;j<=31;j++)
        {
                amt[i][j]=0;
                day[i][j]=j;        
        }        
     }  
     if(fp!=NULL)
     {        
           while(1)
           {                  //int tot=0,temp,max=0;    
		   //max stores the maximum date till which the records are entered
		   //this is done for replacing the total after making change   
                                 fscanf(fp,"%d",&temp);
                                 day[month][temp]=temp; 
                                 if(max<temp)
                                 {
                                    max=temp;            
                                 }                                                                                                               
                                 getc(fp);  //" "                               
                                 getc(fp);  //"-"                             
                                 c=getc(fp);//" "                                
                                 fscanf(fp,"%d",&amt[month][temp]);                                                           
                                 while(c!='\n')
                                 {
                                      c=getc(fp);
                                      if(c==EOF)
                                      {
                                                 break;
                                      }
                                 } 
                                 if(c==EOF)
                                 {
                                             break;
                                 }                                
           }                  
     }           
     fclose(fp);
     
      //rewrite the file 
     //replacing all the data 'w' (not appending anymore)
     //we store all the data of month(in day array) with dates and their amounts(in amt array), then replace one entry that was supposed to be replaced
     //then over write the file again using 'w'
     if(month==1)
     {
           fp=fopen("january.txt","w");
     }
     if(month==2)
     {
           fp=fopen("february.txt","w");
     }
     if(month==3)
     {
           fp=fopen("march.txt","w");
     }
     if(month==4)
     {
           fp=fopen("april.txt","w");
     }
     if(month==5)
     {
           fp=fopen("may.txt","w");
     }
     if(month==6)
     {
           fp=fopen("june.txt","w");
     }
     if(month==7)
     {
           fp=fopen("july.txt","w");
     }
     if(month==8)
     {
           fp=fopen("august.txt","w");
     }
     if(month==9)
     {
           fp=fopen("september.txt","w");
     }
     if(month==10)
     {
           fp=fopen("october.txt","w");
     }
     if(month==11)
     {
           fp=fopen("novembr.txt","w");
     }
     if(month==12)
     {
           fp=fopen("decembr.txt","w");
     } 
     amt[month][date]=amount;//change record
     if(fp!=NULL)
     {            
             for(int k=1;k<=max;k++)
             {
                   tot=0;
                   for(int l=1;l<=k;l++)
                   {			//for each date the total is of all the dates before it
                   				//and we are writing each date data again, from start date
                                tot+=amt[month][l];//obtain new total
                   }
                   fprintf(fp,"%d - %d ",k,amt[month][k]);
                   fprintf(fp,"Updated Expenditure :%d\n",tot);            
             }
     }  
                
     fclose(fp);       
     printf("\nWELL Ur New Record Is Succesfully Added!!!\n")  ; 
}
       
//prints total of all months       
void option4()
{
     printf("\n....SUMMARY...\n");
     printf("January            %d\n",summation(1));
     printf("February           %d\n",summation(2));
     printf("March              %d\n",summation(3));
     printf("April              %d\n",summation(4));
     printf("May                %d\n",summation(5));
     printf("June               %d\n",summation(6));
     printf("August             %d\n",summation(8));
     printf("September          %d\n",summation(9));
     printf("October            %d\n",summation(10));
     printf("November           %d\n",summation(11));
     printf("December           %d\n",summation(12));
}                       
void option5()
{
     exit(0);                   
}         
void option6()
{
    printf("\n\n_____________________________________\n\n");  
    printf("\t\t\t1.Add daily expenditure.\n");
    printf("\t\t\t2.Display daily expenditure.\n");   
    printf("\t\t\t3.Change records.\n");
    printf("\t\t\t4.Display summary of monthly expenditure.\n");
    printf("\t\t\t5.Exit.\n\n");              
}
   
 //function to find total of a given 'month'. This is called from option 4    
int summation(int month)
{
    FILE *fp;
    int i=1,tot=0;
    char c;
    if(month==1)
    {
           fp=fopen("january.txt","r");
    }
    if(month==2)
    {
           fp=fopen("february.txt","r");
    }
    if(month==3)
    {
           fp=fopen("march.txt","r");
    }
    if(month==4)
    {
           fp=fopen("april.txt","r");
    }
    if(month==5)
    {
           fp=fopen("may.txt","r");
    }
    if(month==6)
    {
           fp=fopen("june.txt","r");
    }
    if(month==7)
    {
           fp=fopen("july.txt","r");
    }
    if(month==8)
    {
           fp=fopen("august.txt","r");
    }
    if(month==9)
    {
           fp=fopen("september.txt","r");
    }
    if(month==10)
    {
           fp=fopen("october.txt","r");
    }
    if(month==11)
    {
           fp=fopen("novembr.txt","r");
    }
    if(month==12)
    {
           fp=fopen("decembr.txt","r");
    }
   
    if(fp!=NULL)
    {        
           while(1)
           {                         
                                 fscanf(fp,"%d",&day[month][i]);                                                                                                                
                                 getc(fp);                                 
                                 getc(fp);                                
                                 c=getc(fp);                                
                                 fscanf(fp,"%d",&amt[month][i]);                                                           
                                 while(c!='\n')
                                 {
                                      c=getc(fp);
                                      if(c==EOF)
                                      {
                                                 break;
                                      }
                                  } 
                                  if(c==EOF)
                                  {
                                             break;
                                  }                                
                                  i++;
            }                  
    }           
    fclose(fp);
    for(int k=1;k<i;k++)
    {               
                                tot+=amt[month][k];                                                     
    }
    return tot;                             
}   

