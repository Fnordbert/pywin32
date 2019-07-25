// This file implements the IEmptyVolumeCacheCallBack Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "EmptyVC.h"
#include "PyIEmptyVolumeCacheCallBack.h"

#ifndef PY_LONG_LONG
// Python 2.2 apparently didn't use a PY_ prefix here...
#define PY_LONG_LONG LONG_LONG
#endif

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIEmptyVolumeCacheCallBack::PyIEmptyVolumeCacheCallBack(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIEmptyVolumeCacheCallBack::~PyIEmptyVolumeCacheCallBack() {}

/* static */ IEmptyVolumeCacheCallBack *PyIEmptyVolumeCacheCallBack::GetI(PyObject *self)
{
    return (IEmptyVolumeCacheCallBack *)PyIUnknown::GetI(self);
}

// @pymethod |PyIEmptyVolumeCacheCallBack|ScanProgress|Description of ScanProgress.
PyObject *PyIEmptyVolumeCacheCallBack::ScanProgress(PyObject *self, PyObject *args)
{
    IEmptyVolumeCacheCallBack *pIEVCCB = GetI(self);
    if (pIEVCCB == NULL)
        return NULL;
    DWORDLONG dwlSpaceUsed;
    PyObject *obdwlSpaceUsed;
    // @pyparm long|dwlSpaceUsed||Description for dwlSpaceUsed
    // @pyparm int|dwFlags||Description for dwFlags
    // @pyparm unicode|pcwszStatus||Description for pcwszStatus
    PyObject *obpcwszStatus;
    DWORD dwFlags;
    LPWSTR pcwszStatus;
    if (!PyArg_ParseTuple(args, "OkO:ScanProgress", &obdwlSpaceUsed, &dwFlags, &obpcwszStatus))
        return NULL;
    dwlSpaceUsed = PyLong_AsUnsignedLongLong(obdwlSpaceUsed);
    if (dwlSpaceUsed == (unsigned PY_LONG_LONG) - 1 && PyErr_Occurred())
        return NULL;
    if (!PyWinObject_AsWCHAR(obpcwszStatus, &pcwszStatus))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIEVCCB->ScanProgress(dwlSpaceUsed, dwFlags, pcwszStatus);
    SysFreeString(pcwszStatus);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIEVCCB, IID_IEmptyVolumeCacheCallBack);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIEmptyVolumeCacheCallBack|PurgeProgress|Description of PurgeProgress.
PyObject *PyIEmptyVolumeCacheCallBack::PurgeProgress(PyObject *self, PyObject *args)
{
    IEmptyVolumeCacheCallBack *pIEVCCB = GetI(self);
    if (pIEVCCB == NULL)
        return NULL;
    DWORDLONG dwlSpaceFreed;
    PyObject *obdwlSpaceFreed;
    // @pyparm <o PyDWORDLONG>|dwlSpaceFreed||Description for dwlSpaceFreed
    DWORDLONG dwlSpaceToFree;
    PyObject *obdwlSpaceToFree;
    // @pyparm long|spaceFreed||
    // @pyparm long|spaceToFree||
    // @pyparm long|flags||
    // @pyparm unicode|status||
    PyObject *obpcwszStatus;
    DWORD dwFlags;
    LPWSTR pcwszStatus;
    if (!PyArg_ParseTuple(args, "OOlO:PurgeProgress", &obdwlSpaceFreed, &obdwlSpaceToFree, &dwFlags, &obpcwszStatus))
        return NULL;
    dwlSpaceFreed = PyLong_AsUnsignedLongLong(obdwlSpaceFreed);
    if (dwlSpaceFreed == (unsigned PY_LONG_LONG) - 1 && PyErr_Occurred())
        return NULL;
    dwlSpaceToFree = PyLong_AsUnsignedLongLong(obdwlSpaceToFree);
    if (dwlSpaceToFree == (unsigned PY_LONG_LONG) - 1 && PyErr_Occurred())
        return NULL;
    if (!PyWinObject_AsWCHAR(obpcwszStatus, &pcwszStatus))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIEVCCB->PurgeProgress(dwlSpaceFreed, dwlSpaceToFree, dwFlags, pcwszStatus);
    SysFreeString(pcwszStatus);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIEVCCB, IID_IEmptyVolumeCacheCallBack);
    Py_INCREF(Py_None);
    return Py_None;
}

// @object PyIEmptyVolumeCacheCallBack|Callback used by <o PyIEmptyVolumeCacheCallBack>
static struct PyMethodDef PyIEmptyVolumeCacheCallBack_methods[] = {
    {"ScanProgress", PyIEmptyVolumeCacheCallBack::ScanProgress, 1},  // @pymeth ScanProgress|Description of ScanProgress
    {"PurgeProgress", PyIEmptyVolumeCacheCallBack::PurgeProgress,
     1},  // @pymeth PurgeProgress|Description of PurgeProgress
    {NULL}};

PyComTypeObject PyIEmptyVolumeCacheCallBack::type("PyIEmptyVolumeCacheCallBack", &PyIUnknown::type,
                                                  sizeof(PyIEmptyVolumeCacheCallBack),
                                                  PyIEmptyVolumeCacheCallBack_methods,
                                                  GET_PYCOM_CTOR(PyIEmptyVolumeCacheCallBack));
