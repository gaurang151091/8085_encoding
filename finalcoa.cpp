#include<iostream>
#include<bits/stdc++.h>
#include<graphics.h>
#include<stdio.h>
using namespace std;

class rm{

	public:
	char code[30];
	char str1[30];
    char str2[30];
};
class reg{
	public:
	char code[30];
	char str1[30];
	char str2[30];

};
rm rm0[8],rm1[8],rm2[8];
reg reg5[8];


void initialise()
{



      char a[30],b[30],c[30],d[30];


	int i;
	char code[30];
	FILE *fp;
    fp=fopen("REG.txt","r+");
	for(i=0;i<8;i++)
	{
	fscanf(fp,"%s %s %s \n",reg5[i].code,reg5[i].str1,reg5[i].str2);
	}
	fclose(fp);



    fp=fopen("R-M.txt","r+");
	for(i=0;i<8;i++)
	{
	fscanf(fp,"%s %s %s %s\n",a,b,c,d);
	strcpy(rm0[i].code,a);  strcpy(rm0[i].str1,"00"); strcpy(rm0[i].str2,b);
	strcpy(rm1[i].code,a);   strcpy(rm1[i].str1,"01"); strcpy(rm1[i].str2,c);
strcpy(rm2[i].code,a);    strcpy(rm2[i].str1,"10"); strcpy(rm2[i].str2,d);
}
	fclose(fp);


}


void decode(){
initialise();
char op[6];char mod[2],re[3],ri[3],q,w;
    char co[16];
    char d[16],s[16];
    char oct[10],hex[18];int o1,o2;int h1,h2,h3,h4;

 cout<<"enter 16 bit  instruction format"<<endl;

cin>>co;
    if(co[8]=='0'&&co[9]=='0'){
       if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm0[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm0[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm0[1].str2); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='0'){strcpy(d,rm0[2].str2); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm0[3].str2); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm0[4].str2); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm0[5].str2); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='0'){
        printf("\n enter the 16 bit direct address:\n");
          cin>>hex;
          h1=(hex[15]-'0')+(hex[14]-'0')*2+(hex[13]-'0')*4+(hex[12]-'0')*8;
          h2=(hex[11]-'0')+(hex[10]-'0')*2+(hex[9]-'0')*4+(hex[8]-'0')*8;
          h3=(hex[7]-'0')+(hex[6]-'0')*2+(hex[5]-'0')*4+(hex[4]-'0')*8;
          h4=(hex[3]-'0')+(hex[2]-'0')*2+(hex[1]-'0')*4+(hex[0]-'0')*8;

        strcpy(d,rm0[6].str2); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm0[7].str2); }
    }

    else if(co[8]=='0'&&co[9]=='1'){
        printf("\n enter the 8 bit displacement:\n");
          cin>>oct;
          o1=(oct[7]-'0')+(oct[6]-'0')*2+(oct[5]-'0')*4+(oct[4]-'0')*8;
          o2=(oct[3]-'0')+(oct[2]-'0')*2+(oct[1]-'0')*4+(oct[0]-'0')*8;

       if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm1[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm1[0].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm1[1].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='0'){strcpy(d,rm1[2].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm1[3].str2);d[5]='\0';}
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm1[4].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm1[5].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='0'){strcpy(d,rm1[6].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm1[7].str2); d[2]='\0';}


    }

    else if(co[8]=='1'&&co[9]=='0'){
        printf("\n enter the 16 bit displacement:\n");
          cin>>hex;
          h1=(hex[15]-'0')+(hex[14]-'0')*2+(hex[13]-'0')*4+(hex[12]-'0')*8;
          h2=(hex[11]-'0')+(hex[10]-'0')*2+(hex[9]-'0')*4+(hex[8]-'0')*8;
          h3=(hex[7]-'0')+(hex[6]-'0')*2+(hex[5]-'0')*4+(hex[4]-'0')*8;
          h4=(hex[3]-'0')+(hex[2]-'0')*2+(hex[1]-'0')*4+(hex[0]-'0')*8;

       if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm2[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm2[0].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm2[1].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='0'){strcpy(d,rm2[2].str2);d[5]='\0'; }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm2[3].str2);d[5]='\0'; }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='0'){strcpy(d,rm2[4].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='1'){strcpy(d,rm2[5].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='0'){strcpy(d,rm2[6].str2); d[2]='\0';}
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='1'){strcpy(d,rm2[7].str2); d[2]='\0';}

    }

    else if(co[8]=='1'&&co[9]=='1'){
          if(co[7]=='0'){
       if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[0].str1); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[0].str1); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='1'){strcpy(d,reg5[1].str1); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='0'){strcpy(d,reg5[2].str1); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='1'){strcpy(d,reg5[3].str1); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[4].str1); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='1'){strcpy(d,reg5[5].str1); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='0'){strcpy(d,reg5[6].str1); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='1'){strcpy(d,reg5[7].str1); }}
          else if(co[7]=='1'){

       if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[0].str2); }
       else  if(co[13]=='0'&&co[14]=='0'&&co[15]=='1'){strcpy(d,reg5[1].str2); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='0'){strcpy(d,reg5[2].str2); }
       else  if(co[13]=='0'&&co[14]=='1'&&co[15]=='1'){strcpy(d,reg5[3].str2); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='0'){strcpy(d,reg5[4].str2); }
       else  if(co[13]=='1'&&co[14]=='0'&&co[15]=='1'){strcpy(d,reg5[5].str2); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='0'){strcpy(d,reg5[6].str2); }
       else  if(co[13]=='1'&&co[14]=='1'&&co[15]=='1'){strcpy(d,reg5[7].str2); }

}
    }


    if(co[7]=='0'){
       if(co[10]=='0'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[0].str1); }
       else  if(co[10]=='0'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[0].str1); }
       else  if(co[10]=='0'&&co[11]=='0'&&co[12]=='1'){strcpy(s,reg5[1].str1); }
       else  if(co[10]=='0'&&co[11]=='1'&&co[12]=='0'){strcpy(s,reg5[2].str1); }
       else  if(co[10]=='0'&&co[11]=='1'&&co[12]=='1'){strcpy(s,reg5[3].str1); }
       else  if(co[10]=='1'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[4].str1); }
       else  if(co[10]=='1'&&co[11]=='0'&&co[12]=='1'){strcpy(s,reg5[5].str1); }
       else  if(co[10]=='1'&&co[11]=='1'&&co[12]=='0'){strcpy(s,reg5[6].str1); }
       else  if(co[10]=='1'&&co[11]=='1'&&co[12]=='1'){strcpy(s,reg5[7].str1); }}
          else if(co[7]=='1'){
       if(co[10]=='0'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[0].str2); }
       else  if(co[10]=='0'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[0].str2); }
       else  if(co[10]=='0'&&co[11]=='0'&&co[12]=='1'){strcpy(s,reg5[1].str2); }
       else  if(co[10]=='0'&&co[11]=='1'&&co[12]=='0'){strcpy(s,reg5[2].str2); }
       else  if(co[10]=='0'&&co[11]=='1'&&co[12]=='1'){strcpy(s,reg5[3].str2); }
       else  if(co[10]=='1'&&co[11]=='0'&&co[12]=='0'){strcpy(s,reg5[4].str2); }
       else  if(co[10]=='1'&&co[11]=='0'&&co[12]=='1'){strcpy(s,reg5[5].str2); }
       else  if(co[10]=='1'&&co[11]=='1'&&co[12]=='0'){strcpy(s,reg5[6].str2); }
       else  if(co[10]=='1'&&co[11]=='1'&&co[12]=='1'){strcpy(s,reg5[7].str2); }

}



if(co[0]=='0'&&co[1]=='0'&&co[2]=='0'&&co[3]=='0'&&co[4]=='0'&&co[5]=='0'){
if(co[6]=='0')
{if(co[8]=='1'&&co[9]=='1'){cout <<"ADD"<<"  "<<d<<"  , "<<s;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nADD [  %s+%X%Xh    ] , %s",d,o2,o1,s);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nADD [  %s+%X%X%X%Xh   ] , %s",d,h4,h3,h2,h1,s);}
else{printf("\nADD [  %X%X%X%Xh   ]  %s",h4,h3,h2,h1,s);}
}
else if(co[6]=='1'){if(co[8]=='1'&&co[9]=='1'){
cout <<"ADD"<<"  "<<s<<"  , "<<d;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nADD  %s , [ %s+%X%Xh ] ",s,d,o2,o1);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nADD %s  , [ %s+%X%X%X%Xh   ]  ",s,d,h4,h3,h2,h1);}
else{printf("\nADD %s , [ %X%X%X%Xh ]  ",s,h4,h3,h2,h1);}
}

}


else if(co[0]=='1'&&co[1]=='0'&&co[2]=='0'&&co[3]=='1'&&co[4]=='0'&&co[5]=='0'){
if(co[6]=='0')
{if(co[8]=='1'&&co[9]=='1'){cout <<"ADC"<<"  "<<d<<" ,  "<<s;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nADC [ %s+%X%Xh  ] , %s",d,o2,o1,s);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nADC [ %s+%X%X%X%Xh ] , %s",d,h4,h3,h2,h1,s);}
else{printf("\nADC [ %X%X%X%Xh ] , %s",h4,h3,h2,h1,s);}
}
else if(co[6]=='1'){if(co[8]=='1'&&co[9]=='1'){
cout <<"ADC"<<"  "<<s<<" ,  "<<d;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nADC  %s , [ %s+%X%Xh ] ",s,d,o2,o1);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nADC %s , [ %s+%X%X%X%Xh ]  ",s,d,h4,h3,h2,h1);}
else{printf("\nADC %s , [ %X%X%X%Xh ]  ",s,h4,h3,h2,h1);}
}

}

/*
else if(co[0]=='0'&&co[1]=='0'&&co[2]=='0'&&co[3]=='0'&&co[4]=='1'&&co[5]=='0'){
if(co[6]=='0')
{if(co[8]=='1'&&co[9]=='1'){cout <<"OR"<<"  "<<d<<"   "<<s;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nOR [  %s+%X%Xh    ]  %s",d,o2,o1,s);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nOR [  %s+%X%X%X%Xh   ]  %s",d,h4,h3,h2,h1,s);}
else{printf("\nOR [  %X%X%X%Xh   ]  %s",h4,h3,h2,h1,s);}
}
else if(co[6]=='1'){if(co[8]=='1'&&co[9]=='1'){
cout <<"OR"<<"  "<<s<<"   "<<d;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nOR  %s [   %s+%X%Xh   ] ",s,d,o2,o1);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nOR %s [   %s+%X%X%X%Xh   ]  ",s,d,h4,h3,h2,h1);}
else{printf("\nOR %s [   %X%X%X%Xh   ]  ",s,h4,h3,h2,h1);}
}

}*/


else if(co[0]=='0'&&co[1]=='0'&&co[2]=='1'&&co[3]=='1'&&co[4]=='1'&&co[5]=='0'){
if(co[6]=='0')
{if(co[8]=='1'&&co[9]=='1'){cout <<"CMP"<<"  "<<d<<" ,  "<<s;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nCMP [  %s+%X%Xh  ] , %s",d,o2,o1,s);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nCMP [  %s+%X%X%X%Xh ] , %s",d,h4,h3,h2,h1,s);}
else{printf("\nCMP [  %X%X%X%Xh   ]  %s",h4,h3,h2,h1,s);}
}
else if(co[6]=='1'){if(co[8]=='1'&&co[9]=='1'){
cout <<"CMP"<<"  "<<s<<" ,  "<<d;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nCMP %s , [ %s+%X%Xh   ] ",s,d,o2,o1);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nCMP %s , [ %s+%X%X%X%Xh   ]  ",s,d,h4,h3,h2,h1);}
else{printf("\nCMP %s  ,[ %X%X%X%Xh   ]  ",s,h4,h3,h2,h1);}
}

}


else{
if(co[6]=='0')
{if(co[8]=='1'&&co[9]=='1'){cout <<"MOV"<<"  "<<d<<"  , "<<s;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nMOV [  %s+%X%Xh    ] , %s",d,o2,o1,s);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nMOV [  %s+%X%X%X%Xh   ] , %s",d,h4,h3,h2,h1,s);}
else {printf("\nMOV [  %X%X%X%Xh   ]  %s",h4,h3,h2,h1,s);}
}
else if(co[6]=='1'){if(co[8]=='1'&&co[9]=='1'){
cout <<"MOV"<<"  "<<s<<" ,  "<<d;}
else if(co[8]=='0'&&co[9]=='1'){printf("\nMOV  %s , [ %s+%X%Xh ] ",s,d,o2,o1);}
else if(co[8]=='1'&&co[9]=='0'){printf("\nMOV %s , [ %s+%X%X%X%Xh   ]  ",s,d,h4,h3,h2,h1);}
else{printf("\nMOV %s , [ %X%X%X%Xh ]  ",s,h4,h3,h2,h1);}
}

}




}



void encode(){
initialise();
    int i,j;
    char a[500];
    char c[30],d[30];
    char u[30],m[30];
    int m1=0;
    int m2=0;
    int e=0,l=0;
    int w=0;
    int rm;
    int we;
    string modd;
    int len=0;
    int f=0;
    char rmm[30];
    char reg[30];
    char b[500];
    char disp[10];
    char disp1[10];
    char disp3[10];
    char opcode[30];
    char opc[30];
    int h=0;

int    len1=0;
int z=0;


cout<<"ENTER THE INSTRUCTION :- "<<endl;
 //strcpy(a,"mov ax,bx");
gets(a);
gets(a);
char ch;
i=0;

len=strlen(a);
    for(i=0;i<len;i++)
    {

        if(a[i]==' ')
        {
            }
           else
           {
               b[len1]=a[i];
               len1++;
           }

    }
      b[len1]='\0';
      len1++;

i=4;
j=0;
opcode[0]=b[0];
opcode[1]=b[1];
opcode[2]=b[2];
opcode[3]='\0';
f=0;
h=0;
    if((opcode[h++]=='M'||opcode[j++]=='m')&&(opcode[h++]=='O'||opcode[j++]=='o')&&(opcode[h++]=='V'||opcode[j++]=='v'))
    {
        opc[f++]='1';opc[f++]='0';opc[f++]='0';opc[f++]='0';opc[f++]='1';opc[f++]='0';opc[f]='\0';
    }

j=0;
h=0;
f=0;
    if((opcode[h++]=='a'||opcode[j++]=='A')&&(opcode[h++]=='d'||opcode[j++]=='D')&&(opcode[h++]=='d'||opcode[j++]=='D'))
    {
        opc[f++]='0';opc[f++]='0';opc[f++]='0';opc[f++]='0';opc[f++]='0';opc[f++]='0';opc[f++]='\0';
    }

j=0;
h=0;
f=0;
if((opcode[h++]=='a'||opcode[j++]=='A')&&(opcode[h++]=='d'||opcode[j++]=='D')&&(opcode[h++]=='c'||opcode[j++]=='C'))
    {
        opc[f++]='1';opc[f++]='0';opc[f++]='0';opc[f++]='1';opc[f++]='0';opc[f++]='0';opc[f++]='\0';
    }

j=0;
f=0;
h=0;
if((opcode[h++]=='c'||opcode[j++]=='C')&&(opcode[h++]=='m'||opcode[j++]=='M')&&(opcode[h++]=='p'||opcode[j++]=='P'))
    {
        opc[f++]='0';opc[f++]='0';opc[f++]='1';opc[f++]='1';opc[f++]='1';opc[f++]='0';opc[f++]='\0';
    }

j=0;
f=0;
cout<<"opcode: "<<opc<<endl;


if(b[3]=='[')
{ m1=1;

    while(b[i]!=']')
         {
           c[j]=b[i];
           j++; i++;

         }

         if((c[0]=='0')||(c[0]=='1')||(c[0]=='2')||(c[0]=='3')||(c[0]=='4')||(c[0]=='5')||(c[0]=='6')||(c[0]=='7')||(c[0]=='8')||(c[0]=='9'))
               {
                   z=1;

               }



         i-=4;
         if(b[i]=='+')
         {
             w=1;

         }
         else if(b[i]=='0'||b[i]=='1'||b[i]=='2'||b[i]=='3'||b[i]=='4'||b[i]=='5'||b[i]=='6'||b[i]=='7'||b[i]=='8'||b[i]=='9')
         {
             w=2;
         }
         c[j]='\0';
         j=0; i+=4; i+=2;
    while(b[i]!='\0')
           {
               d[j]=b[i];
               j++;i++;



           }
       d[j]='\0';


           if(d[0]=='0'||d[0]=='1'||d[0]=='2'||d[0]=='3'||d[0]=='4'||d[0]=='5'||d[0]=='6'||d[0]=='7'||d[0]=='8'||d[0]=='9')
           {
               e=1;
           }

}
else
{e=1;
   i--;

    while(b[i]!=',')
         {
           c[j]=b[i];
           j++; i++;
         }
         c[j]='\0';
         i++;
      if(b[i]=='[')
              { m2=1;

                j=0;i++;
                while(b[i]!=']')
                {
                    d[j]=b[i];
                    j++; i++;
                    }

                 if((d[0]=='0')||(d[0]=='1')||(d[0]=='2')||(d[0]=='3')||(d[0]=='4')||(d[0]=='5')||(d[0]=='6')||(d[0]=='7')||(d[0]=='8')||(d[0]=='9'))
               {
                   z=1;
               }

                     i-=4;
                if(b[i]=='+')
               {
                w=1;

                }
                else if(b[i]=='0'||b[i]=='1'||b[i]=='2'||b[i]=='3'||b[i]=='4'||b[i]=='5'||b[i]=='6'||b[i]=='7'||b[i]=='8'||b[i]=='9')
                {
                    w=2;
                }

                 i+=4;
                    d[j]='\0';




              }
      else{ j=0;

             while(b[i]!='\0')
           {
               d[j]=b[i];
               j++;i++;
           }
       d[j]='\0';

            if(d[0]=='0'||d[0]=='1'||d[0]=='2'||d[0]=='3'||d[0]=='4'||d[0]=='5'||d[0]=='6'||d[0]=='7'||d[0]=='8'||d[0]=='9')
            {
                w=4;
            }

            w=4;

           }





}
//cout<<e<<endl;
if(w==0)
{
    modd="00";
}
else if(w==1)
{
    modd="01";
}
else if(w==2)
{
    modd="10";
}
else
{
    modd="11";
}

we=strlen(c);
for(i=0;i<we;i++)
{
    if(c[i]>=97&&c[i]<=122)
    {
        c[i]-=32;
    }
}
we=strlen(d);
for(i=0;i<we;i++)
{
    if(d[i]>=97&&d[i]<=122)
    {
        d[i]-=32;
    }
}





if(strcmp(c,"AL")==0||strcmp(d,"AL")==0||strcmp(c,"CL")==0||strcmp(d,"CL")==0||strcmp(c,"BL")==0||strcmp(d,"BL")==0||strcmp(c,"DL")==0||strcmp(d,"DL")==0||strcmp(c,"AH")==0||strcmp(d,"AH")==0||strcmp(c,"CH")==0||strcmp(d,"CH")==0||strcmp(c,"BH")==0||strcmp(d,"BH")==0||strcmp(c,"DH")==0||strcmp(d,"DH")==0)
{
    we=0;
}
else
{we=1;}
cout<<"w:"<<we<<" D:"<<e<<endl;

strcpy(u,c);
strcpy(m,d);
if(m1==1)
{      if(modd=="01")
               {       i=strlen(c);
                         if(i<9)

                         {   disp[0]=u[3];
                             disp[1]=u[4];
                             disp[2]='\0';
                             u[3]='0';
                             u[4]='8';
                             u[5]='B';
                             u[6]='\0';
                         }
                                             disp1[0]=c[6];
                             disp1[1]=c[7];
                             disp1[2]='\0';

                                c[6]='0';
                                c[7]='8';
                                c[8]='B';
                                c[9]='\0';

               }
           if(modd=="10")
               {          i=strlen(c);
                     disp1[0]=c[6];
                             disp1[1]=c[7];
                             disp1[2]=c[8];
                             disp1[3]=c[9];
                             disp1[4]='\0';
                   c[6]='1';
                   c[7]='6';
                   c[8]='B';
                   c[9]='\0';


                         if(i<9)
                         { disp[0]=u[3];
                             disp[1]=u[4];
                             disp[2]=u[5];
                             disp[3]=u[6];
                             disp[4]='\0';
                   u[3]='1';
                   u[4]='6';
                   u[5]='B';
                   u[6]='\0'; }

               }

}

if(m2==1)
{      if(modd=="01")
               {   i=strlen(d);
                                         disp1[0]=d[6];
                             disp1[1]=d[7];
                             disp1[2]='\0';

                   d[6]='0';
                   d[7]='8';
                   d[8]='B';
                   d[9]='\0';



                         if(i<9)
                         {
                             disp[0]=m[3];
                             disp[1]=m[4];
                             disp[2]='\0';
                   m[3]='0';
                   m[4]='8';
                   m[5]='B';
                   m[6]='\0';}

               }
           if(modd=="10")
               {   i=strlen(d);
                          disp1[0]=d[6];
                             disp1[1]=d[7];
                             disp1[2]=d[8];
                             disp1[3]=d[9];
                             disp1[4]='\0';
                   d[6]='1';
                   d[7]='6';
                   d[8]='B';
                   d[9]='\0';

                         if(i<9)
                         {disp[0]=m[3];
                             disp[1]=m[4];
                             disp[2]=m[5];
                             disp[3]=m[6];
                             disp[4]='\0';
                   m[3]='1';
                   m[4]='6';
                   m[5]='B';
                   m[6]='\0';}

               }

}
if(z==0)
{ cout<<"mod"<<modd<<endl;
    for(i=0;i<8;i++)
{if(modd=="00")
    {   if(m1==1 && we==0)
        {
            if(strcmp(c,rm0[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm0[i].code);}

            if(strcmp(d,reg5[i].str1)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);cout<<endl;}

        }
        else if(m1==1 && we==1)
        {
            if(strcmp(c,rm0[i].str2)==0)
            { cout<<"r/m"; strcpy(rmm,rm0[i].code);}

            if(strcmp(d,reg5[i].str2)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code); cout<<endl;}



        }
        else if(m2==1 && we==0)
        {
            if(strcmp(d,rm0[i].str2)==0)
            {cout<<"r/m"; strcpy(rmm,rm0[i].code);cout<<endl;}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }
        else if(m2==1 && we==1)
        {
            if(strcmp(d,rm0[i].str2)==0)
            {cout<<"r/m";strcpy(rmm,rm0[i].code);cout<<endl;}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }


}
else if(modd=="01")
{        if(m1==1 && we==0)
        {
            if(strcmp(c,rm1[i].str2)==0 ||strcmp(u,rm1[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm1[i].code);}

            if(strcmp(d,reg5[i].str1)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);cout<<endl;}

        }
        else if(m1==1 && we==1)
        {
            if(strcmp(c,rm1[i].str2)==0||strcmp(u,rm1[i].str2)==0)
            { cout<<"r/m ";
            strcpy(rmm,rm1[i].code);}

            if(strcmp(d,reg5[i].str2)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code); cout<<endl;}



        }
        else if(m2==1 && we==0)
        {
            if(strcmp(d,rm1[i].str2)==0 || strcmp(m,rm1[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm1[i].code);}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }
        else if(m2==1 && we==1)
        {
            if(strcmp(d,rm1[i].str2)==0 || strcmp(m,rm1[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm1[i].code);cout<<endl;}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }

}
else if(modd=="10")
{       if(m1==1 && we==0)
        {
            if(strcmp(c,rm2[i].str2)==0 || strcmp(u,rm2[i].str2)==0 )
            {cout<<"r/m ";
            strcpy(rmm,rm2[i].code);}

            if(strcmp(d,reg5[i].str1)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);cout<<endl;}

        }
        else if(m1==1 && we==1)
        {
            if(strcmp(c,rm2[i].str2)==0 || strcmp(u,rm2[i].str2)==0)
            { cout<<"r/m ";
            strcpy(rmm,rm2[i].code);}

            if(strcmp(d,reg5[i].str2)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);cout<<endl;}



        }
        else if(m2==1 && we==0)
        {
            if(strcmp(d,rm2[i].str2)==0 || strcmp(m,rm2[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm2[i].code);cout<<endl;}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }
        else if(m2==1 && we==1)
        {
            if(strcmp(d,rm2[i].str2)==0 || strcmp(m,rm2[i].str2)==0)
            {cout<<"r/m ";
            strcpy(rmm,rm2[i].code);cout<<endl;}

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }

}
else if(modd=="11")
{          if(we==1)
        {
            if(strcmp(c,reg5[i].str2)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);}

            if(strcmp(d,reg5[i].str2)==0)
            { cout<<"r/m ";
            strcpy(rmm,reg5[i].code);cout<<endl;}

        }
        else if( we==0)
        {
            if(strcmp(c,reg5[i].str1)==0)
            {  cout<<"reg";strcpy(reg,reg5[i].code);}

            if(strcmp(d,reg5[i].str1)==0)
            {  cout<<"r/m ";
            strcpy(rmm,reg5[i].code); cout<<endl;}



        }

}
}
}
else if(z==1)
{
    modd="00";
    cout<<"mod"<<modd<<endl;
    strcpy(rmm,"110");

for(i=0;i<8;i++)
{


        if(m1==1 && we==0)
        {

            if(strcmp(d,reg5[i].str1)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code);cout<<endl;}

        }
        else if(m1==1 && we==1)
        {

            if(strcmp(d,reg5[i].str2)==0)
            { cout<<"reg";strcpy(reg,reg5[i].code); cout<<endl;}



        }
        else if(m2==1 && we==0)
        {

            if(strcmp(c,reg5[i].str2)==0)
            {cout<<"reg";strcpy(reg,reg5[i].code);}



        }
        else if(m2==1 && we==1)
        {

            if(strcmp(c,reg5[i].str2)==0)
            {//cout<<"reg";
                strcpy(reg,reg5[i].code);}



        }
}

}
strcpy(disp3,d);
d[0]=modd[0];
d[1]=modd[1];
d[2]='\0';
if(z==1||strcmp(d,"01")==0||strcmp(d,"10")==0)
 { if(z==1)
{        if(m1==1)
             {
                 strcpy(disp3,c); disp3[4]='\0';
             }
         // else
          //{
            //  strcpy(disp3,d);disp3[4]='\0';
          //}
}


else if(rmm[0]=='0')
{    strcpy(disp3,disp1);

}
else{ strcpy(disp3,disp);}

//cout<<endl<<disp3;
if(strlen(disp3)>2)
{
    i=0;
}
else
{
    i=1;
}
strcpy(c,disp3);
int k;
k=i;
j=0;
for(i=0;i<strlen(d);i++)
{
    d[i]=' ';
}
if(k==0)
{
    for(i=0;i<4;i++)
    {if(c[i]=='0')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='1')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='2')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='3')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='4')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='5')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='6')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='7')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='8')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='9')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='A')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='B')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='C')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='D')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='E')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='F')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
    }


    }
    d[j]='\0';

}
else
{ for(i=0;i<2;i++)
    {if(c[i]=='0')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='1')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='2')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='3')
    {
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='4')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='5')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='6')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='7')
    {
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='8')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='9')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='A')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='B')
    {
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
        d[j++]='1';
    }
    if(c[i]=='C')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
        d[j++]='0';
    }
    if(c[i]=='D')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
        d[j++]='1';
    }
    if(c[i]=='E')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
        d[j++]='0';
    }
    if(c[i]=='F')
    {
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
        d[j++]='1';
    }


    }
    d[j]='\0';

}
cout<<endl;
cout<<"displacement :-"<<d<<endl;

cout<<"INSTRUCTION OPCODE IS:";
cout<<endl<<opc<<" "<<e<<" "<<we<<" "<<modd<<" "<<reg<<" "<<rmm<<" "<<d<<endl;
}
else
{
    cout<<"INSTRUCTION OPCODE IS:";
cout<<endl<<opc<<" "<<e<<" "<<we<<" "<<modd<<" "<<reg<<" "<<rmm<<endl;
}

}



main()
{
	  int i;
initwindow(800,600);

     readimagefile("1.jpg",0,0,800,600);
     char ff=getch();

     //readimagefile("3.jpg",0,0,800,600);
 readimagefile("8086.jpg",0,0,800,600);
 settextstyle(8,0,5);
setbkcolor(15);
setcolor(BLUE);
 //outtextxy(250,430,"L O A D I N G . . .");
 for(i=0;i<=800;i+=25)
    {
    bar(0,429,i,470);
    if(i>250)
    {
        outtextxy(150,430,"L");
    }
      if(i>275)
    {

        outtextxy(150,430,"L O");
    }
    if(i>300)
    {
        outtextxy(150,430,"L O A");
    }
    if(i>350)
    {
        outtextxy(150,430,"L O A D");
    }if(i>370)
    {
        outtextxy(150,430,"L O A D I");
    }if(i>405)
    {
        outtextxy(150,430,"L O A D I N");
    }if(i>420)
    {
        outtextxy(150,430,"L O A D I N G");
    }if(i>470)
    {
        outtextxy(150,430,"L O A D I N G .");
    }if(i>510)
    {
        outtextxy(150,430,"L O A D I N G . .");
    }
    if(i>530)
    {
        outtextxy(150,430,"L O A D I N G . . .");

    }
    delay(150);
    }
     readimagefile("1.bmp",0,0,800,600);
closegraph();


	   while(1)
       {


	   cout<<endl<<"want to encode or decode instruction??";
	   cout<<endl<<"1. press 1 for encode"<<endl<<"2. press 2 for decode "<<endl;
	   cout<<"3. press 3 for exit"<<endl;

	   int n;
	   cin>>n;
	   if(n==1)
		{encode();
		}
		else if(n==2)
        {


        decode();
        }
        else if(n==3)
        {

            exit(1);
        }
        cout<<endl<<endl;
        delay(700);
        }

}
