#include <Python.h>

void print_python_list(PyObject *p)
{
    PyListObject *list;
    PyVarObject *var_obj;
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;
    size = var_obj->ob_size;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (i = 0; i < size; ++i)
    {
        item = list->ob_item[i];
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item))
        {
            print_python_bytes(item);
        }
    }
}

void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes;
    PyVarObject *var_obj;
    Py_ssize_t size, i;
    char *string;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;
    size = var_obj->ob_size;

    printf("  size: %zd\n", size);

    string = PyBytes_AsString(p);
    if (string == NULL)
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("  trying string: %s\n", string);

    printf("  first %d bytes: ", size > 10 ? 10 : (int)size);
    for (i = 0; i < (size > 10 ? 10 : size); ++i)
    {
        printf("%02x ", (unsigned char)string[i]);
    }
    printf("\n");
}
