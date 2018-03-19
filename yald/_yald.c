#include <Python.h>
#include "levenshtein.h"

/* Docstrings */
static char module_docstring[] = "This module provides an interface for calculating the levenshtein distance using C.";
static char distance_docstring[] = "Calculate the levenshtein distance for two given strings.";

/* Available functions */
static PyObject *levenshtein_distance(PyObject *self, PyObject *args);

/* Module specification */
static PyMethodDef module_methods[] = {
        {"distance", (PyCFunction) levenshtein_distance, METH_VARARGS, distance_docstring},
        {NULL,       NULL,                               0,            NULL}
};


/* Initialize the module */
PyMODINIT_FUNC PyInit_yald(void) {
    PyObject *module;
    static struct PyModuleDef moduledef = {
            PyModuleDef_HEAD_INIT,
            "yald",
            module_docstring,
            -1,
            module_methods,
            NULL,
            NULL,
            NULL,
            NULL,
    };

    module = PyModule_Create(&moduledef);
    if (!module) return NULL;

    return module;
}


static PyObject *levenshtein_distance(PyObject *self, PyObject *args) {
    PyObject *s1, *s2;

    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "ss", &s1, &s2))
        return NULL;

    /* Call the external C function to compute the levenshtein distance. */
    unsigned int value = levenshtein_dist(s1, s2);

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("i", value);
    return ret;
}
