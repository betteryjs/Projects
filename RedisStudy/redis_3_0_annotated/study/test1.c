//
// Created by yjs on 23-3-29.
//

#include "../src/sds.h"
#include "stdio.h"
#include <string.h>


//void sdsupdatelen(sds s) {
//    // get sdshdr pointer
//    struct sdshdr *sh = (void*) (s-(sizeof(struct sdshdr)));
//    int reallen = strlen(s);
//    sh->free += (sh->len-reallen);
//    sh->len = reallen;
//}


int main(){
    sds s = sdsnew("foobar");
    s[2] = '\0';
    sdsupdatelen(s);
    printf("%d\n", (int)sdslen(s));
    printf("%d\n", sizeof (struct sdshdr));

    return 0;
}