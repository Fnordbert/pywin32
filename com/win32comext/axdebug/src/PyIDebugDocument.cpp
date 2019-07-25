// This file implements the IDebugDocument Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"

#include "PyIDebugDocumentInfo.h"
#include "PyIDebugDocument.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIDebugDocument::PyIDebugDocument(IUnknown *pdisp) : PyIDebugDocumentInfo(pdisp) { ob_type = &type; }

PyIDebugDocument::~PyIDebugDocument() {}

/* static */ IDebugDocument *PyIDebugDocument::GetI(PyObject *self) { return (IDebugDocument *)PyIUnknown::GetI(self); }

// @object PyIDebugDocument|The base interface to all debug documents.  Derived from <o PyIDebugDocumentInfo>
static struct PyMethodDef PyIDebugDocument_methods[] = {{NULL}};

PyComTypeObject PyIDebugDocument::type("PyIDebugDocument", &PyIDebugDocumentInfo::type, sizeof(PyIDebugDocument),
                                       PyIDebugDocument_methods, GET_PYCOM_CTOR(PyIDebugDocument));
// ---------------------------------------------------
//
// Gateway Implementation

// Std delegation
// IDebugDocumentInfo
STDMETHODIMP PyGDebugDocument::GetName(DOCUMENTNAMETYPE dnt, BSTR *pbstrName)
{
    return PyGDebugDocumentInfo::GetName(dnt, pbstrName);
}
STDMETHODIMP PyGDebugDocument::GetDocumentClassId(CLSID *pclsidDocument)
{
    return PyGDebugDocumentInfo::GetDocumentClassId(pclsidDocument);
}
