



static int
PyDeferredArray_init(PyDeferredArrayObject *self, PyObject *args, PyObject *kwds)
{
    if (PyArray_Type.tp_init((PyObject *)self, args, kwds) < 0)
        return -1;
    self->materialized = 0;
    return 0;
}

NPY_NO_EXPORT PyTypeObject PyDeferredArray_Type = {
#if defined(NPY_PY3K)
    PyVarObject_HEAD_INIT(NULL, 0)
#else
    PyObject_HEAD_INIT(NULL)
    0,                                          /* ob_size */
#endif
    "numpy.deferredarray",         /* tp_name */
    sizeof(PyDeferredArrayObject),          /* tp_basicsize */
    0,                       /* tp_itemsize */
    0,                       /* tp_dealloc */
    0,                       /* tp_print */
    0,                       /* tp_getattr */
    0,                       /* tp_setattr */
    0,                       /* tp_compare */
    0,                       /* tp_repr */
    0,                       /* tp_as_number */
    0,                       /* tp_as_sequence */
    0,                       /* tp_as_mapping */
    0,                       /* tp_hash */
    0,                       /* tp_call */
    0,                       /* tp_str */
    0,                       /* tp_getattro */
    0,                       /* tp_setattro */
    0,                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
      Py_TPFLAGS_BASETYPE,   /* tp_flags */
    0,                       /* tp_doc */
    0,                       /* tp_traverse */
    0,                       /* tp_clear */
    0,                       /* tp_richcompare */
    0,                       /* tp_weaklistoffset */
    0,                       /* tp_iter */
    0,                       /* tp_iternext */
    0,          /* tp_methods */
    0,                       /* tp_members */
    0,                       /* tp_getset */
    0,                       /* tp_base */
    0,                       /* tp_dict */
    0,                       /* tp_descr_get */
    0,                       /* tp_descr_set */
    0,                       /* tp_dictoffset */
    (initproc)PyDeferredArray_init,   /* tp_init */
    0,                       /* tp_alloc */
    0,                       /* tp_new */
};

npy_bool PyDeferredArray_Materialize(PyObject* op) {
    if (!PyDeferredArray_Check(op)) {
        return 1;
    }
    if (((PyDeferredArrayObject*)op)->materialized) {
        return 1;
    }
    return 0;
}