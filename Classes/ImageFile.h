//
//  ImageFile.h
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#ifndef __mir_new_Demo__ImageFile__
#define __mir_new_Demo__ImageFile__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
typedef struct tgaImgDesc
{
	//unsigned short idx;
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short h;
	short cx;
	short cy;
} ImgDesc, *pImgDesc;


typedef struct tagImgHead
{
    double CreateTime;
    unsigned short Imagecount;
    unsigned short Imagetype;
    unsigned short width;
    unsigned short Height;
    
}ImgHead,pImgHead;


typedef struct tgaImgBody
{
    int Index;
    unsigned short x;
    unsigned short y ;
    unsigned short width;
    unsigned short height;
    short offsetx;
    short offsety;
}ImgBody,*pImgBody;

class CImageFile: public Ref
{
private:
    __String  m_ImageFileName;
    
    ImgDesc * ImgNode;
protected:
    
public:
    CImageFile();
    virtual ~CImageFile();
    
    
    
    bool LoadBinFile();
    
    void SetFileName(char * cfilename);
    
    
};


#endif /* defined(__mir_new_Demo__ImageFile__) */
