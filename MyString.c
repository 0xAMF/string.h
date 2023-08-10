#include <stdio.h>
#include <locale.h>
#include "MyString.h"

void *my_memchr(const void *str, char c, unsigned int size)
{
    unsigned char *tmpStr = (unsigned char *)str;
    if (str == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (size--)
        {
            if (c == *tmpStr)
            {
                /* Found */
                str = tmpStr;
                break;
            }
            else
            {
                tmpStr++;
            }
        }
        if (size == 0)
        {
            tmpStr = NULL;
        }
    }
    return tmpStr;
}

unsigned int my_memcmp(const void *str1, const void *str2, unsigned int size)
{
    unsigned int returnValue = 0;
    unsigned char *tmpStr1 = (unsigned char *)str1;
    unsigned char *tmpStr2 = (unsigned char *)str2;

    if (str1 == NULL || str2 == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (size--)
        {
            if (*tmpStr1 != *tmpStr2)
            {
                returnValue = (*tmpStr1 < *tmpStr2) ? -1 : 1;
                break;
            }
            else
            {
                /* Same Value */
                tmpStr1++;
                tmpStr2++;
            }
        }
    }
    return returnValue;
}

void *my_memcpy(void *dest, const void *src, unsigned int size)
{
    unsigned char *tmpDest = (unsigned char *)dest;
    unsigned char *tmpSrc = (unsigned char *)src;

    if (dest == NULL || src == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (size--)
        {
            *tmpDest++ = *tmpSrc++;
        }
    }

    return dest;
}

void *my_memmove(void *dest, const void *src, unsigned int size)
{
    unsigned char *tmpDest = (unsigned char *)dest;
    unsigned char *tmpSrc = (unsigned char *)src;
    unsigned char *interBuffer;

    if (dest == NULL || src == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (size--)
        {
            *interBuffer++ = *tmpSrc++;
        }
        tmpDest = interBuffer;
    }

    return dest;
}

void *my_memset(void *dest, char c, unsigned int size)
{
    unsigned char *tempDest = dest;
    if (dest == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (size--)
        {
            *tempDest = c;
            tempDest++;
        }
        
    }

    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    char *tempSrc = (unsigned char *)src;
    char *tempDest = dest;
    unsigned int srcLength = my_strlen(tempSrc);
    unsigned int destLength = my_strlen(tempDest);
    char *destFull = tempDest + destLength;

    if (dest == NULL || src == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (srcLength--)
        {
            *destFull++ = *tempSrc++;
        }
    }

    return dest;
}

char *my_strncat(char *dest, const char *src, unsigned int n)
{
    char *tempDest = dest;
    char *tempSrc = (char *)src;
    char destLength = my_strlen(dest);
    char *destFull = tempDest + destLength;

    if (dest == NULL || src == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (n--)
        {
            *destFull++ = *tempSrc++;
        }
        
    }
    
}

char *my_strchr(const char *str, int c)
{
    unsigned int strLength = my_strlen(str);
    char *tempString = (char *)str;
    char *returnValue = NULL;

    if (str == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (strLength--)
        {
            if (*tempString == c)
            {
                returnValue = tempString;
                break;
            }
            else
            {
                tempString++;
            }
        }
    }

    return returnValue; 
}

int my_strcmp(const char *str1, const char *str2)
{
    int returnValue = 0;
    char *tempStr1 = (char *)str1;
    char *tempStr2 = (char *)str2;

    if (str1 == NULL || str2 == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (*tempStr1 != '\0' || *tempStr2 != '\0')
        {
            if (*tempStr1 != *tempStr2)
            {
                returnValue = (*tempStr1 < *tempStr2) ? -1 : 1;
                break;
            }
            else
            {
                tempStr1++;
                tempStr2++;
            }
        }
        
    }

    return returnValue;
}

int my_strncmp(const char *str1, const char *str2, unsigned int n)
{
    int returnValue = 0;
    char *tempStr1 = (char *)str1;
    char *tempStr2 = (char *)str2;

    if (str1 == NULL || str2 == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (n--)
        {
           if (*tempStr1 != *tempStr2)
           {
                returnValue = (*tempStr1 < *tempStr2) ? -1 : 1;
           }
            
        }
        
    }

   return returnValue; 
}

int my_strcoll(const char *str1, const char *str2)
{
    int returnValue = 0;
    char *tempStr1 = (char *)str1;
    char *tempStr2 = (char *)str2;
    int str1Length = my_strlen(str1);
    int str2Length = my_strlen(str2);
    
    if (str1 == NULL || str2 == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        setlocale(LC_COLLATE, "");
        while (*tempStr1 != '\0' || *tempStr2 != '\0')
        {
            if (*tempStr1 != *tempStr2)
            {
                returnValue = (*tempStr1 < *tempStr2) ? -1 : 1;
                break;
            }
            else
            {
                tempStr1++;
                tempStr2++;
            } 
            
        }
        
    }


   return returnValue; 
}

char *my_strcpy(char *dest, const char *src)
{
    char *tempDest = dest;
    char *tempSrc = (char *)src;

    if (tempDest == NULL || tempSrc == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (*tempSrc != '\0')
        {
            *tempDest++ = *tempSrc++;
        }
    }

    return dest;
}

char *my_strncpy(char *dest, const char *src, unsigned int n)
{
    char *tempDest = dest;
    char *tempSrc = (char *)src;

    if (tempDest == NULL || tempSrc == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (n--)
        {
            *tempDest++ = *tempSrc++;
            if (*tempSrc == '\0')
            {
                *tempDest = '\0';
            }
               
        }
    }
    
}

unsigned int my_strcspn(const char *str1, const char *str2)
{
    unsigned int index = 0;
    char *tempStr1 = (char *)str1;
    char *tempStr2 = (char *)str2;
    unsigned char foundFlag = 0;
    unsigned int counter1 = 0;
    unsigned int counter2 = 0;
    unsigned int len1 = my_strlen(str1);
    unsigned int len2 = my_strlen(str2);

    if (tempStr1 == NULL || tempStr2 == NULL)
    {
        printf("NULL pointer error!\n");
    }
    else
    {
        for (counter2 = 0; counter2 < len2; counter2++)
        {
            tempStr1 = (char *)str1;
            for (counter1 = 0; counter1 < len1; counter1++)
            {
                if (*tempStr1 == *tempStr2)
                {
                    index = counter1;
                    foundFlag = 1;
                    break;
                }
                else
                {
                    tempStr1++;   
                }
            }
            tempStr2++;
        }
        if (foundFlag == 0)
        {
            index = counter1; /* Not found */
        }
    }

   return index; 
}

unsigned int my_strlen(const char *str)
{
    unsigned int length = 0;

    if (str == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (*str != '\0')
        {
            length++;
            str++;
        }
        

    }

    return length;
}


char *my_strpbrk(const char *str1, const char *str2)
{
    char *tempStr1 = (char *)str1;
    char *tempStr2 = (char *)str2;
    unsigned int counter1 = 0;
    unsigned int counter2 = 0;
    unsigned int len1 = my_strlen(str1);
    unsigned int len2 = my_strlen(str2);
    char *c = NULL;

    if (tempStr1 == NULL || tempStr2 == NULL) 
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        for (counter2 = 0; counter2 < len2; counter2++)
        {
            tempStr1 = (char *)str1;
            for (counter1 = 0; counter1 < len1; counter1++)
            {
                if (*tempStr1 == *tempStr2)
                {
                    c = tempStr1;
                    break;
                }
                else
                {
                    tempStr1++;   
                }
            }
            tempStr2++;
        }
    }

    return c;
}

char *my_strrchr(const char *str, int c)
{
    char *tempStr = (char *)str;
    unsigned int counter = 0;
    char *returnChar = NULL;

    if (tempStr == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        for (counter = my_strlen(str); counter > 0; counter--)
        {
            if (*(tempStr + counter) == c)
            {
                returnChar = tempStr + counter;
                break;
            }
            
        }
        
    }

    return returnChar;
}

unsigned int my_strspn(const char *str1, const char *str2)
{
   unsigned int length = 0;
   char *tempStr1 = (char *)str1;
   char *tempStr2 = (char *)str2;

   if (tempStr1 == NULL || tempStr2 == NULL)
   {
        printf("NULL pointer error!!\n");
   }
   else
   {
        while (*tempStr2 != '\0')
        {
            if (*tempStr1 == *tempStr2)
            {
                length++;
                tempStr1++;
                tempStr2++;
            }
            else
            {
                break;
            }
        }
   }

   return length;  
}

char *my_strstr(const char *haystack, const char *needle)
{
    char *tempHaystack = (char *)haystack;
    char *tempNeedle = (char *)needle;
    char *returnNeedle = NULL;

    if (tempHaystack == NULL || tempNeedle == NULL)
    {
        printf("NULL pointer error!!\n");
    }
    else
    {
        while (*tempNeedle != '\0')
        {
            while (*tempHaystack != '\0')
            {
                if (*tempHaystack != *tempNeedle)
                {
                    tempNeedle = NULL;
                    tempHaystack++;
                }
                else
                {
                    tempNeedle++;
                    returnNeedle = tempHaystack;
                }
            }
        }
    }
    
    return returnNeedle;
}

