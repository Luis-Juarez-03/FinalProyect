
// CorrectorWinDlg.h: archivo de encabezado
//

#pragma once
#include "..\quisodecir\corrector.h"
#include "afxwin.h"

// Cuadro de di�logo de CCorrectorWinDlg
class CCorrectorWinDlg : public CDialogEx
{
// Construcci�n
public:
	CCorrectorWinDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_CORRECTORWIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementaci�n
protected:
	HICON m_hIcon;

	// Funciones de asignaci�n de mensajes generadas
	int FuncEPRActiv(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_rutaDiccionario;
	afx_msg void OnBnClickedButton2();

	char	szNombre[MAX_PATH];
	char	szPalabras[NUMPALABRAS][TAMTOKEN];
	int		iEstadisticas[NUMPALABRAS];
	int		iNumElementos;
	CEdit txtTextoCapturado;
	afx_msg void OnCambiaTextoPredectivo();
	CListBox m_lstPrediccion;
	CString m_sTextoCapturado;
	char	szPalabraLeida[TAMTOKEN];
	char	szPalabrasSugeridas[3300][TAMTOKEN];
	char	szListaFinal[3300][TAMTOKEN];
	int		iPeso[3300]; //son 66 combinaciones por letra, mas o menos 3300 para 50 letras
	int		iCandidatas[3300]; //son 66 combinaciones por letra, mas o menos 3300 para 50 letras
	int		iNumLista;
	int		iNumSugeridas;
	CButton m_btnCargar;
};
