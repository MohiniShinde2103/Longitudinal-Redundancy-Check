#include<stdio.h>
#include<conio.h>
int binaryeven(int);
void parityeven(int [],int []);
int binaryodd(int);
void parityodd(int [],int []);
int arr[8],arr1[8],parityarr[8];
char chr;
int go,temp,temp1,i;
void main()
{       char chr1;
	int ch;
	clrscr();
	go=0;
	Sender:
	    if(go==0)
	    printf("\t\t****** Longitudinal Redundancy Check ******\n");
	    printf("\nEnter any two characters : ");
	    scanf("%c %c",&chr,&chr1);
	    do
	    {
	    printf("\nEnter choice:\n1.Even Parity\n2.Odd Parity\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	      case 1:temp=chr;
		     binaryeven(temp);
		     printf("\n\nAscii value of 1st character is : %d\n",temp);
		     printf("\nBinary Form : ");
		     for(i=7;i>=0;i--)
		     {
			arr1[i]=arr[i];
			printf("%d ",arr[i]);
		     }
		     printf("\n");
		     temp1=chr1;
		     binaryeven(temp1);
		     printf("\n\nAscii value of 2nd character is : %d\n",temp1);
		     printf("\nBinary Form : ");
		     for(i=7;i>=0;i--)
		     {
			printf("%d ",arr[i]);
		     }
		     parityeven(arr,arr1);
		     for(i=7;i>=0;i--)
		     {
			arr[i]=0;
			arr1[i]=0;
		     }
		     break;
	      case 2:temp=chr;
		     binaryodd(temp);
		     printf("\n\nAscii value of 1st character is : %d\n",temp);
		     printf("\nBinary Form : ");
		     for(i=7;i>=0;i--)
		     {
			arr1[i]=arr[i];
			printf("%d ",arr[i]);
		     }
		     printf("\n");
		     temp1=chr1;
		     binaryodd(temp1);
		     printf("\n\nAscii value of 2nd character is : %d\n",temp1);
		     printf("\nBinary Form : ");
		     for(i=7;i>=0;i--)
		     {
			printf("%d ",arr[i]);
		     }
		     parityodd(arr,arr1);
		     for(i=7;i>=0;i--)
		     {
			arr[i]=0;
			arr1[i]=0;
		     }
		     break;
	      default:printf("Invalid case\nPlease enter your choice again:");
	    }
	    }
	    while(ch!=3);
	    getch();
}
void parityeven(int arr[],int arr1[])
{
	    printf("\n\nReceiver Side :\n");
	    printf("\nLRC :\n\t");
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",arr[i]);
	    }
	    printf("\n\t");
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",arr1[i]);
	    }
	    printf("\n\t---------------\n\t");
	    for(i=0;i<8;i++)
	    {
		  if(arr[i]==0 && arr1[i]==0 || arr[i]==1 && arr1[i]==1)
		  {
			parityarr[i]=0;
		  }
		  else if(arr[i]==1 && arr1[i]==0 || arr[i]==0 && arr1[i]==1)
		  {
			parityarr[i]=1;
		  }
	    }
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",parityarr[i]);
	    }
}
int binaryeven(int x)
{
	    int rem;
	    int ctr=0,i=1;
	    do
	    {
		 rem=x%2;
		 arr[i]=rem;
		 if(rem==1)
		 {
		     ctr++;
		 }
		 x=x/2;
		 i++;
	    }
	    while(x!=0);
	    if(ctr%2==0)
	    {
		 arr[0]=0;
	    }
	    else
	    {
		 arr[0]=1;
	    }
	    return(0);
}
void parityodd(int arr[],int arr1[])
{
	    printf("\n\nReceiver Side :\n");
	    printf("\nLRC :\n\t");
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",arr[i]);
	    }
	    printf("\n\t");
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",arr1[i]);
	    }
	    printf("\n\t---------------\n\t");
	    for(i=0;i<8;i++)
	    {
		  if(arr[i]==0 && arr1[i]==0 || arr[i]==1 && arr1[i]==1)
		  {
			parityarr[i]=1;
		  }
		  else if(arr[i]==1 && arr1[i]==0 || arr[i]==0 && arr1[i]==1)
		  {
			parityarr[i]=0;
		  }
	    }
	    for(i=7;i>=0;i--)
	    {
		  printf("%d ",parityarr[i]);
	    }
}
int binaryodd(int x)
{
	    int rem;
	    int ctr=0,i=1;
	    do
	    {
		 rem=x%2;
		 arr[i]=rem;
		 if(rem==1)
		 {
		     ctr++;
		 }
		 x=x/2;
		 i++;
	    }
	    while(x!=0);
	    if(ctr%2==0)
	    {
		 arr[0]=1;
	    }
	    else
	    {
		 arr[0]=0;
	    }
	    return(0);
}