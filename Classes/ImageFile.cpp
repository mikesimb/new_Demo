//
//  ImageFile.cpp
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#include "ImageFile.h"

CImageFile::CImageFile()
{
    
}

CImageFile::~CImageFile()
{
    
}

bool CImageFile::LoadBinFile(char * cfilename)
{
    std::string str = CCFileUtils::getInstance()->fullPathForFilename(cfilename);
	ssize_t nsize = 0;
	const char* bin = (const char*)CCFileUtils::getInstance()->getFileData(str.c_str(), "rb", &nsize);//加载文件
    if(nsize > 0)
    {
        memcpy(&m_ImgHead, bin, sizeof(ImgHead));
        if(m_ImgHead.Imagecount >0 )
        {
            m_ImgBody = new ImgBody[m_ImgHead.Imagecount];
            for (int i = 0; i < m_ImgHead.Imagecount; i++)
			{
				memcpy(m_ImgBody, &bin[sizeof(ImgHead) + i * sizeof(ImgBody)], sizeof(ImgBody));
 			}
            
        }
        
    }
    
}


void CImageFile::SetFileName(char *cfilename)
{
	
}