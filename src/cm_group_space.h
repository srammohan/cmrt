/*
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *     Wei Lin<wei.w.lin@intel.com>
 *     Yuting Yang<yuting.yang@intel.com>
 */
#pragma once

class CmDevice;

class CmThreadGroupSpace {
 public:
	static INT Create(CmDevice * pDevice, UINT index, UINT thrdSpaceWidth,
			  UINT thrdSpaceHeight, UINT grpSpaceWidth,
			  UINT grpSpaceHeight, CmThreadGroupSpace * &pTGS);
	static INT Destroy(CmThreadGroupSpace * &pTGS);

	INT GetThreadGroupSpaceSize(UINT & threadSpaceWidth,
				    UINT & threadSpaceHeight,
				    UINT & groupSpaceWidth,
				    UINT & groupSpaceHeight) const;
	UINT GetIndexInTGsArray();

 protected:
	 CmThreadGroupSpace(CmDevice * pCmDev, UINT index, UINT thrdSpaceWidth,
			    UINT thrdSpaceHeight, UINT grpSpaceWidth,
			    UINT grpSpaceHeight);
	~CmThreadGroupSpace(void);
	INT Initialize(void);

	CmDevice *m_pCmDev;
	UINT m_threadSpaceWidth;
	UINT m_threadSpaceHeight;
	UINT m_groupSpaceWidth;
	UINT m_groupSpaceHeight;

	UINT m_IndexInTGSArray;
};
