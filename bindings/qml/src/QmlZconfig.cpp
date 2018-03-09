/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlZconfig.h"


///
//  Return name of config item
const QString QmlZconfig::name () {
    return QString (zconfig_name (self));
};

///
//  Return value of config item
const QString QmlZconfig::value () {
    return QString (zconfig_value (self));
};

///
//  Insert or update configuration key with value
void QmlZconfig::put (const QString &path, const QString &value) {
    zconfig_put (self, path.toUtf8().data(), value.toUtf8().data());
};

///
//  Equivalent to zconfig_put, accepting a format specifier and variable
//  argument list, instead of a single string value.
void QmlZconfig::putf (const QString &path, const QString &format) {
    zconfig_putf (self, path.toUtf8().data(), "%s", format.toUtf8().data());
};

///
//  Get value for config item into a string value; leading slash is optional
//  and ignored.
const QString QmlZconfig::get (const QString &path, const QString &defaultValue) {
    return QString (zconfig_get (self, path.toUtf8().data(), defaultValue.toUtf8().data()));
};

///
//  Set config item name, name may be NULL
void QmlZconfig::setName (const QString &name) {
    zconfig_set_name (self, name.toUtf8().data());
};

///
//  Set new value for config item. The new value may be a string, a printf
//  format, or NULL. Note that if string may possibly contain '%', or if it
//  comes from an insecure source, you must use '%s' as the format, followed
//  by the string.
void QmlZconfig::setValue (const QString &format) {
    zconfig_set_value (self, "%s", format.toUtf8().data());
};

///
//  Find our first child, if any
QmlZconfig *QmlZconfig::child () {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_child (self);
    return retQ_;
};

///
//  Find our first sibling, if any
QmlZconfig *QmlZconfig::next () {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_next (self);
    return retQ_;
};

///
//  Find a config item along a path; leading slash is optional and ignored.
QmlZconfig *QmlZconfig::locate (const QString &path) {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_locate (self, path.toUtf8().data());
    return retQ_;
};

///
//  Locate the last config item at a specified depth
QmlZconfig *QmlZconfig::atDepth (int level) {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_at_depth (self, level);
    return retQ_;
};

///
//  Execute a callback for each config item in the tree; returns zero if
//  successful, else -1.
int QmlZconfig::execute (zconfig_fct handler, void *arg) {
    return zconfig_execute (self, handler, arg);
};

///
//  Add comment to config item before saving to disk. You can add as many
//  comment lines as you like. If you use a null format, all comments are
//  deleted.
void QmlZconfig::setComment (const QString &format) {
    zconfig_set_comment (self, "%s", format.toUtf8().data());
};

///
//  Return comments of config item, as zlist.
QmlZlist *QmlZconfig::comments () {
    QmlZlist *retQ_ = new QmlZlist ();
    retQ_->self = zconfig_comments (self);
    return retQ_;
};

///
//  Save a config tree to a specified ZPL text file, where a filename
//  "-" means dump to standard output.
int QmlZconfig::save (const QString &filename) {
    return zconfig_save (self, filename.toUtf8().data());
};

///
//  Equivalent to zconfig_save, taking a format string instead of a fixed
//  filename.
int QmlZconfig::savef (const QString &format) {
    return zconfig_savef (self, "%s", format.toUtf8().data());
};

///
//  Report filename used during zconfig_load, or NULL if none
const QString QmlZconfig::filename () {
    return QString (zconfig_filename (self));
};

///
//  Save a config tree to a new memory chunk
QmlZchunk *QmlZconfig::chunkSave () {
    QmlZchunk *retQ_ = new QmlZchunk ();
    retQ_->self = zconfig_chunk_save (self);
    return retQ_;
};

///
//  Save a config tree to a new null terminated string
QString QmlZconfig::strSave () {
    char *retStr_ = zconfig_str_save (self);
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Return true if a configuration tree was loaded from a file and that
//  file has changed in since the tree was loaded.
bool QmlZconfig::hasChanged () {
    return zconfig_has_changed (self);
};

///
//  Destroy subtree (all children)
void QmlZconfig::removeSubtree () {
    zconfig_remove_subtree (self);
};

///
//  Print the config file to open stream
void QmlZconfig::fprint (FILE *file) {
    zconfig_fprint (self, file);
};

///
//  Print properties of object
void QmlZconfig::print () {
    zconfig_print (self);
};


QObject* QmlZconfig::qmlAttachedProperties(QObject* object) {
    return new QmlZconfigAttached(object);
}


///
//  Reload config tree from same file that it was previously loaded from.
//  Returns 0 if OK, -1 if there was an error (and then does not change
//  existing data).
int QmlZconfigAttached::reload (QmlZconfig *selfP) {
    return zconfig_reload (&selfP->self);
};

///
//  Load a config tree from a memory chunk
QmlZconfig *QmlZconfigAttached::chunkLoad (QmlZchunk *chunk) {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_chunk_load (chunk->self);
    return retQ_;
};

///
//  Load a config tree from a null-terminated string
QmlZconfig *QmlZconfigAttached::strLoad (const QString &string) {
    QmlZconfig *retQ_ = new QmlZconfig ();
    retQ_->self = zconfig_str_load (string.toUtf8().data());
    return retQ_;
};

///
//  Destroy node and subtree (all children)
void QmlZconfigAttached::remove (QmlZconfig *selfP) {
    zconfig_remove (&selfP->self);
};

///
//  Self test of this class
void QmlZconfigAttached::test (bool verbose) {
    zconfig_test (verbose);
};

///
//  Create new config item
QmlZconfig *QmlZconfigAttached::construct (const QString &name, QmlZconfig *parent) {
    QmlZconfig *qmlSelf = new QmlZconfig ();
    qmlSelf->self = zconfig_new (name.toUtf8().data(), parent->self);
    return qmlSelf;
};

///
//  Load a config tree from a specified ZPL text file; returns a zconfig_t
//  reference for the root, if the file exists and is readable. Returns NULL
//  if the file does not exist.
QmlZconfig *QmlZconfigAttached::load (const QString &filename) {
    QmlZconfig *qmlSelf = new QmlZconfig ();
    qmlSelf->self = zconfig_load (filename.toUtf8().data());
    return qmlSelf;
};

///
//  Equivalent to zconfig_load, taking a format string instead of a fixed
//  filename.
QmlZconfig *QmlZconfigAttached::loadf (const QString &format) {
    QmlZconfig *qmlSelf = new QmlZconfig ();
    qmlSelf->self = zconfig_loadf ("%s", format.toUtf8().data());
    return qmlSelf;
};

///
//  Destroy a config item and all its children
void QmlZconfigAttached::destruct (QmlZconfig *qmlSelf) {
    zconfig_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
