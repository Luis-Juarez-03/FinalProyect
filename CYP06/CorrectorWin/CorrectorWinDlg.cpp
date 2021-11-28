
// CorrectorWinDlg.cpp: archivo de implementaci�n
//

#include "stdafx.h"
#include "CorrectorWin.h"
#include "CorrectorWinDlg.h"

#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de di�logo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de di�logo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementaci�n
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de di�logo de CCorrectorWinDlg


int CCorrectorWinDlg::FuncEPRActiv(void)
{

	// El a�o
	SYSTEMTIME SystemTime;
	int iUso;
	GetLocalTime(&SystemTime);
	iUso=(SystemTime.wYear == (WORD)2021 ||SystemTime.wYear == (WORD)2020);
	return iUso;
}

CCorrectorWinDlg::CCorrectorWinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCorrectorWinDlg::IDD, pParent)
	, m_rutaDiccionario(_T(""))
	, m_sTextoCapturado(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCorrectorWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_rutaDiccionario);
	DDX_Control(pDX, IDC_EDIT4, txtTextoCapturado);
	DDX_Control(pDX, IDC_LIST1, m_lstPrediccion);
	DDX_Text(pDX, IDC_EDIT4, m_sTextoCapturado);
	DDX_Control(pDX, IDC_BUTTON2, m_btnCargar);
}

BEGIN_MESSAGE_MAP(CCorrectorWinDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCorrectorWinDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCorrectorWinDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &CCorrectorWinDlg::OnCambiaTextoPredectivo)
END_MESSAGE_MAP()


// Controladores de mensaje de CCorrectorWinDlg

BOOL CCorrectorWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de men� "Acerca de..." al men� del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de di�logo. El marco de trabajo realiza esta operaci�n
	//  autom�ticamente cuando la ventana principal de la aplicaci�n no es un cuadro de di�logo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono peque�o

	// TODO: agregar aqu� inicializaci�n adicional
	if (!FuncEPRActiv())
	{
		MessageBox("Gracias por estudiar. UNAM 2015","Computadoras y programacion",MB_OK);
		this->OnCancel();
	}

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCorrectorWinDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un bot�n Minimizar al cuadro de di�logo, necesitar� el siguiente c�digo
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operaci�n la realiza autom�ticamente el marco de trabajo.

void CCorrectorWinDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rect�ngulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta funci�n para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCorrectorWinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCorrectorWinDlg::OnBnClickedButton1()
{
	
	CString s;
	CFileDialog dlgFile(TRUE);
	dlgFile.DoModal();
	

	m_rutaDiccionario=dlgFile.GetPathName();
	strcpy_s(szNombre,m_rutaDiccionario.GetBuffer());

	m_btnCargar.EnableWindow(true);

	UpdateData(false);

}


void CCorrectorWinDlg::OnBnClickedButton2()
{
	HCURSOR  hCursor;
	hCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);

	::SetCursor(hCursor);

	Diccionario(szNombre, szPalabras, iEstadisticas, iNumElementos);
	txtTextoCapturado.EnableWindow(true);
	hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);

	::SetCursor(hCursor);
}


void CCorrectorWinDlg::OnCambiaTextoPredectivo()
{
	// TODO:  Si �ste es un control RICHEDIT, el control no
	// enviar� esta notificaci�n a menos que se invalide CDialogEx::OnInitDialog()
	// funci�n y llamada CRichEditCtrl().SetEventMask()
	// con el marcador ENM_CHANGE ORed en la m�scara.

	// TODO:  Agregue aqu� el controlador de notificaci�n de controles
	UpdateData(true);
	m_lstPrediccion.ResetContent();
	
	strcpy_s(szPalabraLeida,m_sTextoCapturado.GetBuffer());
	_strlwr_s(szPalabraLeida);
	
	ClonaPalabras(szPalabraLeida, szPalabrasSugeridas, iNumSugeridas);
	ListaCandidatas(szPalabrasSugeridas, iNumSugeridas, szPalabras, iEstadisticas, iNumElementos,
						szListaFinal, iPeso, iNumLista);

	for (int i = 0; i < iNumLista; i++)
	{
		m_lstPrediccion.AddString(szListaFinal[i]);
	}

	UpdateData(false);
}
