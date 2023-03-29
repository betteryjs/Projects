//
// Created by yjs on 23-3-29.
//

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void vout(char *string, char *fmt, ...)

{
    va_list arg_ptr;

    va_start(arg_ptr, fmt);
    vsprintf(string, fmt, arg_ptr);
    printf("--arg_ptr-- %s\n",(char *)arg_ptr);

    va_end(arg_ptr);
}

char fmt1 [] = "%s  %s  %s\n";

int main(void)
{
    char string[100];
    vout(string,fmt1,"Sat", "Sun", "Mon");
//    vout(string, fmt1, "Sat", "Sun", "Mon");
    printf("The string is:  %s\n", string);
//    char string2[100];
//    sprintf(string2, fmt1,"Sat2", "Sun2", "Mon2");
//    printf("The string2 is:  %s\n", string2);


}
