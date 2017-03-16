void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
  }
}

void reverseWords(char *s)
{
    if(!s || *s == '\0')
        return;
    char *word_begin = NULL;
    char *temp = s; 

    int length = 0;
    while(*temp != '\0')
    {
        length++;
        temp++;
    }
    reverse(s, s + length -1);

    temp = s;
    int wordIndex = 0;
    for(int i = 0; i < length; i++)
    {
        if(s[i] != ' ')
        {
                int j = i;
                if(wordIndex != 0)
                {
                    s[wordIndex] = ' ';
                    wordIndex++;
                }
                while(s[j] != ' ' && j < length)
                {
                    s[wordIndex] = s[j];
                    wordIndex++;
                    j++;
                }
                reverse(s + wordIndex - (j - i), s + wordIndex - 1);
                i = j;
        }
    }

    for(int i = wordIndex; i < length; i++)
        s[i] = '\0';
} 