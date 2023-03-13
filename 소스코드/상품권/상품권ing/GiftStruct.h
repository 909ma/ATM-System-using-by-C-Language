//
//  GiftStruct.h
//  atm상품권거래
//
//  Created by 최은지 on 2023/03/10.
//

#ifndef GiftStruct_h
#define GiftStruct_h
#include <stdio.h>

typedef struct {
    char gift_num[11];
    char expiry_date[11];
    int balance;
} gift_struct;



#endif /* GiftStruct_h */
