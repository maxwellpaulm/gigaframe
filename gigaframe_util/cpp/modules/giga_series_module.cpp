//
// Created by maxwe on 8/13/2022.
//
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#ifdef __cplusplus
#include "../interface/giga_series.h"
#endif


typedef struct {
    PyObject_HEAD GigaSeries* gs_obj;
} PyGigaSeries;


static struct PyModuleDef giga_series_module = {
    PyModuleDef_HEAD_INIT,
    "giga_series",
    "A giga series module.",
    -1,
    NULL, NULL, NULL, NULL
};

static struct PyModuleDef giga_index_module = {
    PyModuleDef_HEAD_INIT,
    "giga_index",
    "A giga index module.",
    -1,
    NULL, NULL, NULL, NULL
};

// Python GigaSeries class
static int PyGigaSeries_init(PyGigaSeries *self, PyObject *args, PyObject *kwargs) {
    self->gs_obj = new StaticGigaSeries();
    return 0;
}

static void PyGigaSeries_dealloc(PyGigaSeries *self) {
    delete self->gs_obj;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* PyGigaSeries_get_length(PyGigaSeries* self, PyObject* args) {
    return PyLong_FromUnsignedLongLong(self->gs_obj->get_length());
}

static PyObject* PyGigaSeries_get_bytes(PyGigaSeries* self, PyObject* args) {
    return PyLong_FromUnsignedLong(self->gs_obj->get_bytes());
}

static PyMethodDef PyGigaSeries_methods[] = {
        {"get_length", (PyCFunction)PyGigaSeries_get_length, METH_NOARGS, "Get the length of the giga series."},
        {"get_bytes", (PyCFunction)PyGigaSeries_get_bytes, METH_NOARGS, "Get the bytes in the giga series."},
        {NULL}
};

static PyTypeObject PyGigaSeries_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "giga_series.GigaSeries" // tp_name
};

PyMODINIT_FUNC PyInit_giga_series(void) {
    PyObject *m;
    PyGigaSeries_Type.tp_new = PyType_GenericNew;
    PyGigaSeries_Type.tp_name = "giga_series.GigaSeries";
    PyGigaSeries_Type.tp_basicsize = sizeof(PyGigaSeries);
    PyGigaSeries_Type.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
    PyGigaSeries_Type.tp_doc = "A giga series extension.";
    PyGigaSeries_Type.tp_methods = PyGigaSeries_methods;
    PyGigaSeries_Type.tp_init = (initproc) PyGigaSeries_init;
    PyGigaSeries_Type.tp_dealloc = (destructor) PyGigaSeries_dealloc;

    if (PyType_Ready(&PyGigaSeries_Type) < 0) {
        return NULL;
    }

    m = PyModule_Create(&giga_series_module);
    if (!m) {
        return NULL;
    }

    Py_INCREF(&PyGigaSeries_Type);
    PyModule_AddObject(m, "GigaSeries", (PyObject*) &PyGigaSeries_Type);

    return m;
}


int main(int argc, char *argv[]) {
    wchar_t* program = Py_DecodeLocale(argv[0], NULL);

    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    /* Add a built-in module, before Py_Initialize */
    if (PyImport_AppendInittab("giga_series", PyInit_giga_series) == -1) {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
        exit(1);
    }

    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(program);

    /* Initialize the Python interpreter.  Required.
       If this step fails, it will be a fatal error. */
    Py_Initialize();

    /* Optionally import the module; alternatively,
       import can be deferred until the embedded script
       imports it. */
    PyObject* pmodule = PyImport_ImportModule("giga_series");
    if (!pmodule) {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'giga_series'\n");
    }

    PyMem_RawFree(program);
    return 0;
}
