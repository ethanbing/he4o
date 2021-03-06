//
//  AIPort.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/9/7.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------网络端口类--------------------
 *  用来替代AILine+AIStrong
 */
@class AIKVPointer,AIPortStrong;
@interface AIPort : NSObject <NSCoding>

@property (strong,nonatomic) AIPointer *target_p;   //指向目标的地址
@property (strong,nonatomic) AIPortStrong *strong;

//-(NSComparisonResult) compare:(AIPort*)port;//类比port:1级强度,2级pointerId;
-(void) strongPlus;

@end


/**
 *  MARK:--------------------端口强度--------------------
 *  注:为简化设计;
 *  1. 由AINode.xxxPorts替代了AILineType
 *  2. 由AIPortStrong替代了AILineStrong
 *  3. 互相关联,不表示强度值一致,所以A与B关联,有可能A的强度为3,B却为100;
 */
@interface AIPortStrong : NSObject <NSCoding>


@property (assign,nonatomic) NSInteger value;
@property (assign, nonatomic) double updateTime;  //更新值时间(18.07.13目前未工作,随后补上)

//(警告!!!强度不能在strong内部自行改变,不然会影响到第二序列的工作,所以应由第二序列读取到内存时,统一调用处理;)
-(void) updateValue;//更新衰减值(1,时间衰减; 2,衰减曲线;)(目前先每天减1;)
-(NSComparisonResult) compare:(AIPortStrong*)strong;

@end
