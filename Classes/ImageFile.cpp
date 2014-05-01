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

bool CImageFile::LoadBinFile()
{
    
}


void CImageFile::SetFileName(char *cfilename)
{
    CActorMotionDesc* pNode = NULL;
    
	//œ»≤È «∑Ò“—ª∫¥Ê
	CCObject* pObj;
	CCARRAY_FOREACH(m_MotionList, pObj)
	{
		pNode = (CActorMotionDesc*)pObj;
		int ret = strcmp(pNode->name, szFile);
		if ((pNode) && (ret == 0))
		{
			return pNode;
		}
	}
	std::string str = CCFileUtils::sharedFileUtils()->fullPathForFilename(szFile);
	ssize_t nsize = 0;
	const char* bin = (const char*)CCFileUtils::sharedFileUtils()->getFileData(str.c_str(), "rb", &nsize);
	if (nsize > 0)
	{
		TActorMotionHead head;
		TActorMotionBody body;
		int headlen = sizeof(TActorMotionHead);
		int bodylen = sizeof(TActorMotionBody);
        
		memcpy(&head, bin, headlen);
        
		// ±ÿ–Î–£—È≥§∂»
		if (nsize == headlen + head.ImageCount * bodylen)
		{
            
			pNode = new CActorMotionDesc();
			pNode->retain();
			m_MotionList->addObject(pNode);
            
			pNode->idx = 0;
			sprintf(pNode->name, "%s", szFile);
			pNode->IsEnabled = true;
			pNode->maxDescNum = MAX_CREATURE_NUM;
            
			for (int i = 0; i < head.ImageCount; i++)
			{
				memcpy(&body, &bin[headlen + i * bodylen], bodylen);
                
				pNode->ActNodes[body.Index].x = body.X;
				pNode->ActNodes[body.Index].y = body.Y;
				pNode->ActNodes[body.Index].w = body.Width;
				pNode->ActNodes[body.Index].h = body.Height;
				pNode->ActNodes[body.Index].cx = body.OffsetX;
				pNode->ActNodes[body.Index].cy = body.OffsetY;
                
			}
		}
		
	}
    
	return pNode;
}