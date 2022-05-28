void Palindrome(char str[]){
	int l = 0;
	int h = strlen(str) - 1;
	 while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is not a palindrome\n", str);
            return;
        }
        else{
        	printf("%s is a palindrome\n",str);
		}
    }
    
}

int main(){
	char str[30];
	printf("Enter string:");
	scanf("%s",&str);
	Palindrome(str);
}
