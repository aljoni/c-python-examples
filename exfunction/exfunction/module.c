#define PY_SSIZE_T_CLEAN
#include <Python.h>

// Defines the function 'exfunction.add'
static PyObject *
exfunction_add(PyObject *self, PyObject *args)
{
	// Parse arguments
	long a, b;
	if (!PyArg_ParseTuple(args, "ll", &a, &b))
	{
		return NULL;
	}

	// Perform addition
	long c = a + b;

	// Return result, as a Python object
	return PyLong_FromLong(c);
}

static PyMethodDef exfunction_methods[] = {
	{"add", exfunction_add, METH_VARARGS, "Add two numbers."},
	{NULL, NULL, 0, NULL}
};

// Defines the module 'exfunction'
static PyModuleDef exfunction_module = {
	PyModuleDef_HEAD_INIT,
	.m_name = "exfunction",
	.m_doc = "Example function module.",
	.m_size = -1,
	.m_methods = exfunction_methods
};

PyMODINIT_FUNC
PyInit_exfunction()
{
	// Attempt to create module
	PyObject *module = PyModule_Create(&exfunction_module);
	if (module == NULL)
	{
		return NULL;
	}

	// Return 'exfunction' module
	return module;
}
