/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#ifndef Q_ZDIGEST_H
#define Q_ZDIGEST_H

#include "qczmq.h"

class QT_CZMQ_EXPORT QZdigest : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZdigest (zdigest_t *self, QObject *qObjParent = 0);

    //  Constructor - creates new digest object, which you use to build up a
    //  digest by repeatedly calling zdigest_update() on chunks of data.
    explicit QZdigest (QObject *qObjParent = 0);

    //  Destroy a digest object
    ~QZdigest ();

    //  Add buffer into digest calculation
    void update (const byte *buffer, size_t length);

    //  Return final digest hash data. If built without crypto support,
    //  returns NULL.
    const byte * data ();

    //  Return final digest hash size
    size_t size ();

    //  Return digest as printable hex string; caller should not modify nor
    //  free this string. After calling this, you may not use zdigest_update()
    //  on the same digest. If built without crypto support, returns NULL.
    const QString string ();

    //  Self test of this class.
    static void test (bool verbose);

    zdigest_t *self;
};
#endif //  Q_ZDIGEST_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
