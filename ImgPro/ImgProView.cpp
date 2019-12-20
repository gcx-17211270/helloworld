// ImgProView.cpp : implementation of the CImgProView class
//

#include "stdafx.h"
#include "ImgPro.h"

#include "ImgProDoc.h"
#include "ImgProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgProView

IMPLEMENT_DYNCREATE(CImgProView, CView)

BEGIN_MESSAGE_MAP(CImgProView, CView)
	//{{AFX_MSG_MAP(CImgProView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CImgProView::Color)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgProView construction/destruction

CImgProView::CImgProView()
{
	// TODO: add construction code here
	image = 0;
	outImg = 0;
	findex = 0;

}

CImgProView::~CImgProView()
{
	if( image )
		delete image;
	if( outImg )
		delete outImg;
}

BOOL CImgProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImgProView drawing

void CImgProView::OnDraw(CDC* pDC)
{
	CImgProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	if( image == 0 )
		return;

	int i, j;
	if(rawflag == 1)
	{
		BYTE gray;
		for( i=0; i<height; i++)
		{
			for( j=0; j<width; j++)
			{
				gray = image[i*width+j];
				pDC->SetPixel( j, i, RGB(gray,gray,gray));

			}
		}
	}
	//////   show outImg here //////////////////////

	if(bmpflag == 1)
	{
		BYTE r,g,b;
		for( i=0; i<height; i++ )
			for( j=0; j<3*width; j=j+3 )
			{
				b = rgbimg[i*3*width+j];
				g = rgbimg[i*3*width+j+1];
				r = rgbimg[i*3*width+j+2];
				pDC->SetPixelV( j/3, i, RGB(r, g, b) );
			}
	}
	if(flag == 1)
	{
		BYTE r, g, b;
		BYTE gray;
		if(huiimg)
		{
			for( i=0; i<height; i++)
			{
				for( j=0; j<width; j++)
				{
					if (huiimg[i * width + j] == 0) {
						gray = 255;
						pDC->SetPixel(j + width + 10, i, RGB(gray, gray, gray));
					}
					else
					{
						b = rgbimg[i * 3 * width + j*3];
						g = rgbimg[i * 3 * width + j *3+ 1];
						r = rgbimg[i * 3 * width + j *3+ 2];
						pDC->SetPixel(j + width + 10,i,RGB(r, g, b));
					}
					

				}
			}
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CImgProView printing

BOOL CImgProView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImgProView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImgProView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImgProView diagnostics

#ifdef _DEBUG
void CImgProView::AssertValid() const
{
	CView::AssertValid();
}

void CImgProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImgProDoc* CImgProView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImgProDoc)));
	return (CImgProDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImgProView message handlers

void CImgProView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog MyFDlg(TRUE, NULL,NULL, OFN_HIDEREADONLY, NULL,NULL );

	MyFDlg.m_ofn.lpstrFilter = "(*.lst;*.raw;*.bmp)\0*.lst;*.raw;*.bmp\0";
	MyFDlg.m_ofn.lpstrInitialDir = "C:\\Users\\潘先铧\\Desktop\\WPSLIB\\图像处理大作业\\3\\3\\图像";

	flag=0;
	bmpflag = 0;
	rawflag = 0;

	if( MyFDlg.DoModal() == IDOK )
	{
		CString SFName;

		SFName = MyFDlg.GetPathName( ); //full name with path

		char *fnstr;
		fnstr = SFName.GetBuffer(4); //read the name from string 

		FILE *fpLst;
		int n;

		int len;
		len = strlen( fnstr );
		if( !strcmp( fnstr+len-3, "raw" ) ) //single raw image
		{
			rawflag = 1;
			fnum = 0;
			char *ptr;
			ptr = fnstr+len-3;
			while( *ptr != '\\')
				ptr--;
			*ptr = 0;
			strcpy( directory, fnstr);//Directory

			fnames = new char[500];
			strcpy( fnames, ptr+1); //image name
		}
		if( !strcmp( fnstr+len-3, "lst" ) ) //list file
		{
			bmpflag = 1;
			fpLst = fopen( fnstr, "rb");
			fscanf( fpLst, "%3d", &fnum);
			fscanf( fpLst, "%s", directory);//directory

			fnames = new char[fnum*100];
			for( n=0; n<fnum; n++)
				fscanf( fpLst, "%s", fnames+n*100);// image names

			fclose(fpLst);
		}
		if( !strcmp( fnstr+len-3, "bmp" ) )
		{
			bmpflag = 1;
			fnum = 0;
			char *ptr;
			ptr = fnstr+len-3;
			while( *ptr != '\\')
				ptr--;
			*ptr = 0;
			strcpy( directory, fnstr);//Directory

			fnames = new char[500];
			strcpy( fnames, ptr+1); //image name

			findex = 0;
		}
		readImg( findex);
	}
}	

void CImgProView::readImg( int findex)
{

	char fullName[120];
	sprintf( fullName, "%s\\%s", directory, fnames+findex*100);

	FILE *fpImg;
	fpImg = fopen( fullName, "rb");
	if( fpImg==0 )
	{
		AfxMessageBox( "Cannot open the list file", MB_OK, 0 );
		return;
	}

	CString sFTitle;
	sFTitle.Format( "%s", fnames+findex*100 );

	CImgProDoc* pDoc;
	pDoc = GetDocument();
	pDoc->SetTitle( sFTitle );

	int bicount;

	BITMAPFILEHEADER bmpFHeader;
	BITMAPINFOHEADER bmiHeader;

	fread( &bmpFHeader, sizeof(BITMAPFILEHEADER), 1, fpImg );
	fread( &bmiHeader, sizeof(BITMAPINFOHEADER), 1, fpImg );

	width = bmiHeader.biWidth;
	height = bmiHeader.biHeight;
	bicount = bmiHeader.biBitCount;


	BYTE* rowBuff;
	int rowLen;

	rowLen = ((width*bicount)/8+3)/4 *4;
	rowBuff = new BYTE [rowLen];

	if(bicount == 8)
	{
		RGBQUAD bmiColors[256];
		fread( bmiColors, sizeof(RGBQUAD), 256, fpImg );
		image = new BYTE [width*height];
		rgbimg = new BYTE [3*width*height];
		for( int i=height-1; i>=0; i-- )
		{
			fread( rowBuff, 1, rowLen, fpImg );
			memcpy( image+i*width, rowBuff, width );
		}
		for( int i=0; i<height; i++ )
			for(int j=0; j<3*width; j=j+3 )
			{
				rgbimg[i*3*width+j] = bmiColors[ image[i*width+j/3] ].rgbBlue;
				rgbimg[i*3*width+j+1] = bmiColors[ image[i*width+j/3] ].rgbGreen;
				rgbimg[i*3*width+j+2] = bmiColors[ image[i*width+j/3] ].rgbRed;
			}
	}
	if(bicount == 24)
	{
		image = new BYTE [width*height];
		rgbimg = new BYTE [rowLen*height];
		for( int i=height-1; i>=0; i-- )
		{
			fread( rowBuff, 1, rowLen, fpImg );
			memcpy( rgbimg+i*3*width, rowBuff, 3*width );
		}
	}
	delete rowBuff;

	fclose(fpImg);

////////////////////////////////////////////////////////////

    OnInitialUpdate();
}

void CImgProView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if( nChar == VK_NEXT)
	{
		if( findex < fnum )
		{
			findex++;
			readImg( findex );
			if(huiimg!=NULL)
			{
				huiimg=NULL;
			}
		}
	}
	if( nChar == VK_PRIOR )
	{
		if( findex > 0 )
		{
			findex--;
			readImg( findex );
			if(huiimg!=NULL)
			{
				huiimg=NULL;
			}
		}
	}	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CImgProView::OnFileSave() 
{
	// TODO: Add your command handler code here
	char str[40], *ptr;
	sprintf( str, fnames+findex*40 );
	ptr = str;
	while( *ptr!='.' )
		ptr ++;
	*ptr = 0;

	char fname[80];
	sprintf( fname, "D:\\out%s.raw", str );

	FILE* fpOut;
	fpOut = fopen( fname, "wb" );

	fwrite( &width, 4, 1, fpOut );
	fwrite( &height, 4, 1, fpOut );
	fwrite( outImg, 1, width*height, fpOut );

	fclose( fpOut );

}



void CImgProView::Color()
{
	// TODO: 在此添加命令处理程序代码
    BYTE r,g,b;
	int i,j;
	double hg,hr;
	double max1=0.0;
	BYTE gray;
	BYTE* huiimg1;
	gray = 0;
	
	huiimg = new BYTE[width * height];
	huiimg1 = new BYTE[width * height];
	BYTE max, min, delta;
	double h, s, v;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			b = rgbimg[i * 3 * width + j * 3];//i*3干嘛
			g = rgbimg[i * 3 * width + j * 3 + 1];
			r = rgbimg[i * 3 * width + j * 3 + 2];

			max = (r > g) ? r : g;
			max = (max > b) ? max : b;

			min = (r < g) ? r : g;
			min = (min < b) ? min : b;

			delta = max - min;
			if (delta == 0)
				h = 0;
			else
			{
				if (max == r && g >= b)
					h = double(60 * (g - b)) / delta;
				if (max == r && g < b)
					h = double(60 * (g - b)) / delta + 360;
				if (max == g)
					h = double(60 * (b - r)) / delta + 120;
				if (max == b)
					h = double(60 * (r - g)) / delta + 240;
			}

			v = max;
			if (v == 0)
			{
				s = 0;
			}
			else
				s = double(delta) / max;
			if (h < 0)
				h += 360;
			if ((h <= 270.0 && 208.0 <= h) && s > 0.52)
			{
				huiimg1[i * width + j] = 255;
			}
			else
			{
				huiimg1[i * width + j] = 0;
			}
			if ((h <= 270.0 && 205.0 <= h) && s > 0.48)
			{
				huiimg[i * width + j] = 255;
			}
			else
			{
				huiimg[i * width + j] = 0;
			}
		}

	}
	BYTE* tempout;
	BYTE* tempout2;
	tempout = new BYTE[width * height];
	tempout2 = new BYTE[width * height];
	
	erosion(huiimg1, width, height, tempout,1);         //first腐蚀then膨胀
	dilation(tempout, width, height, tempout2,2);
	erosion(tempout2, width, height, tempout, 1);
	dilation(tempout, width, height, huiimg1, 1);

	int maxh, maxw, minh, minw;
	maxw = height / 10; maxh = width / 10; minh = 9 * height / 10; minw = 9 * width / 10;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i > height * 3 / 10 && i < height * 19 / 22 && j>width * 3 / 10 && j < 19 * width / 22) {
				if (huiimg1[i * width + j] == 255 && j < minw) {
					minw = j;
				}
				if (huiimg1[i * width + j] == 255 && j > maxw) {
					maxw = j;
				}
			}
		}
	}

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i > height * 3 / 10 && i < height * 19 / 22 && j>width * 3 / 10 && j < 19 * width / 22) {
				if (huiimg1[i * width + j] == 255 && i < minh) {
					minh = i;
				}
				if (huiimg1[i * width + j] == 255 && i > maxh) {
					maxh = i;
				}
			}
		}
	}

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i >= minh && i <= maxh && j <= maxw && j >= minw) {
				huiimg[i * width + j] = 255;
			}
			else {
				huiimg[i * width + j] = 0;
			}
		}
	}
		flag=1;
		OnInitialUpdate();
}

void CImgProView::dilation(BYTE* image, int w, int h, BYTE* outImg, int p)
{
	int rept;
	memcpy(outImg, image, sizeof(BYTE) * width * height);
	int i, j, m, n;
	BYTE flag;
	for (rept = 0; rept < p; rept++) {
		for (i = 1; i < h - 1; i++) {
			for (j = 1; j < w - 1; j++) {
				if (image[i * w + j] == 0) {
					flag = 0;
					for (m = -1; m < 2; m++) {
						for (n = -1; n < 2; n++) {
							if (image[(i + m) * w + j + n] == 255) {
								flag++;
								break;
							}
						}
					}
					if (flag > 0)
						outImg[i * w + j] = 255;
				}
			}
		}
		memcpy(image, outImg, sizeof(BYTE) * width * height);
	}
}

void CImgProView::erosion(BYTE* image, int w, int h, BYTE* outImg,int p)
{
	int rept;
	memcpy(outImg, image, sizeof(BYTE) * width * height);
	int i, j, m, n;
	BYTE flag;
	for (rept = 0; rept < p; rept++) {
		for (i = 1; i < h - 1; i++) {
			for (j = 1; j < w - 1; j++) {
				if (image[i * w + j] == 255) {
					flag = 0;
					for (m = -1; m < 2; m++) {
						for (n = -1; n < 2; n++) {
							if (image[(i + m) * w + j + n] == 0) {
								flag++;
								break;
							}
						}
					}
					if (flag > 0)
						outImg[i * w + j] = 0;
				}
			}
		}
		memcpy(image, outImg, sizeof(BYTE) * width * height);
	}
}