/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LANTRANSPORT_H
#define LANTRANSPORT_H

#include <QHostAddress>
#include <QSslConfiguration>
#include <QSslSocket>
#include <QTcpSocket>

#include <nitroshare/transport.h>

class Application;

/**
 * @brief Local network transport
 *
 * This class facilitates transfers between devices on a local network. This
 * consists of simple TCP connections with optional TLS encryption (and
 * verification).
 */
class LanTransport : public Transport
{
    Q_OBJECT

public:

    LanTransport(QSslConfiguration *configuration, const QHostAddress &address, quint16 port);
    LanTransport(QSslConfiguration *configuration, qintptr socketDescriptor);

    virtual void start();
    virtual void write(const QByteArray &data);
    virtual void abort();

private slots:

    void onEncrypted();
    void onReadyRead();

private:

    LanTransport(QSslConfiguration *configuration);

    QTcpSocket *mSocket;
    QSslSocket *mSslSocket;
};

#endif // LANTRANSPORT_H
