#include "QHttpContent.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpContent::QHttpContent()
	: QHttpObject()
	, m_content()
{
}

QHttpContent::QHttpContent(const QByteArray& content)
	: QHttpObject()
	, m_content(content)
{
}

QHttpContent::~QHttpContent()
{
}

void QHttpContent::setContent(const QByteArray& content)
{
	m_content = content;
}

QByteArray QHttpContent::content() const
{
	return m_content;
}






