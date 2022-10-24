#include <stdio.h>
 
 char c[]="yhesocvxduiglbkrztnwjpfmaq";
 char s[200];
 int T,i,ts;
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	gets(s);
 	sscanf(s,"%d",&T);
 	while(T--)
 	{
 		gets(s);		
 		for(i=0;s[i];i++)
 			if(s[i]>='A' && s[i]<='Z')
 				s[i]=c[s[i]-'A']-'a'+'A';
 			else if(s[i]>='a' && s[i]<='z')
 				s[i]=c[s[i]-'a'];
 		printf("Case #%d: %s\n",++ts,s);
 	}
 	return 0;
 }