#ifndef XPLANE_CONNECT_H
#define XPLANE_CONNECT_H

#include <QUdpSocket>
#include <QThread>
#include <QSharedPointer>
#include "struct.h"
#include <QMap>
#include <map>
using namespace std;
#include <QList>
#include <QtCore/qglobal.h>
#include <datadisplay.h>

#ifdef CONNECTXPLANE_LIB
# define CONNECTXPLANE_EXPORT Q_DECL_EXPORT
#else
# define CONNECTXPLANE_EXPORT Q_DECL_IMPORT
#endif

class CONNECTXPLANE_EXPORT XplaneConnect : public QThread
{
	Q_OBJECT

public:
	XplaneConnect(QObject *parent = 0);
	~XplaneConnect();
	//����λ����Ϣ
	void requestPosition(int freq);
	//�趨xplaneλ����Ϣ
	void setPosition(veh1_struct pos);
	//��������
	void requestDataref(int freq, int index, QString dataref);
	//�趨����
	void setXplaneDataref(float svalue, QString dataref);
	//xplane�ڲ�����
	void setXplaneCommand(QString cmdStr);
	//�趨����λ��
	void setPlaneAirport(papt_struct airport);
	//��ʼ����
	void startConnect();
	//ֹͣ����
	void stopConnect();
	//�Ƿ�������
	bool isConnected;
	//�Ƿ���ʾ���ݴ���
	void showDisplayWindow(bool b);
	void setXplaneAddress(QString addr);
	QString getXplaneAddress();

	DataDisplay *getDisplayWidget();

private:
	QSharedPointer<QUdpSocket> socket;

	QSharedPointer<QUdpSocket> xplaneFinder;

	//Ҫ��ȡ������,�Լ���ȡ��Ӧ���ݵ�Ƶ��
	QMap<int, QPair<int,QString> > drefMap;
	//������xplane���͵�����
	QMap<COMMANDS, QString> cmdMap;
	//��ȡ��Ϣ�е�����
	COMMANDS getCommand(char *buff, int &pos);
	//��ȡ��Ϣ����
	void getMessageData(char *buff, int &len);
	void getMessageData(char *buff, int &len, QHostAddress host);
	DataDisplay *display;
	QTimer *timer;
	bool isListen;
	QString xplaneAddress;
signals:
	//��ȡ����λ����Ϣ
	void doGetPosition(position_struct pos);
	//��ȡ����������Ϣ
	void doGetDatarefs(QList<dref_struct_out> list);
	//��ȡ����xplane���鲥��Ϣ
	void doGetBecn(becn_struct becn,QHostAddress host);

	private slots :
		void onStartRequestPosition(int freq);
		void onStartRequestDataref(int freq, int index, QString dataref);
		void onSetXplaneDataref(float svalue, QString dataref);
		void onSetPosition(veh1_struct pos);
		void onSetXplaneCommand(QString cmdStr);
		void onSetPlaneAirport(papt_struct airport);
		//��ȡ��Ϣ������
		void readXplaneData();

		void readBecnData();

		//�߳̿�ʼ
		void onThreadStart();
		//
		void onGetPosition(position_struct pos);
		void onGetDatarefs(QList<dref_struct_out> list);
		//�߳̽���
		void onFinished();

		void onTimeout();

		void onConnected();

};

#endif // XPLANE_CONNECT_H
