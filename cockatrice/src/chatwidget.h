#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "servereventdata.h"
#include "client.h"

class QListWidget;
class QTextEdit;
class QLineEdit;
class QTreeWidget;
class QTabWidget;
class QPushButton;

class ChannelWidget : public QWidget {
	Q_OBJECT
private:
	QListWidget *playerList;
	QTextEdit *textEdit;
	QLineEdit *sayEdit;
	Client *client;
	QString name;
private slots:
	void sendMessage();
public:
	ChannelWidget(Client *_client, const QString &_name, QWidget *parent = 0);
	const QString &getName() const { return name; }
	
	void joinEvent(const QString &playerName);
	void listPlayersEvent(const QString &playerName);
	void leaveEvent(const QString &playerName);
	void sayEvent(const QString &playerName, const QString &s);
};

class ChatWidget : public QWidget {
	Q_OBJECT
private:
	QTreeWidget *channelList;
	QPushButton *joinButton;
	QTabWidget *tab;
	Client *client;
	
	ChannelWidget *getChannel(const QString &name);
private slots:
	void chatEvent(const ChatEventData &data);
	void joinClicked();
	void joinFinished(ServerResponse resp);
public:
	ChatWidget(Client *_client, QWidget *parent = 0);
	void retranslateUi();
	void enableChat();
	void disableChat();
};

#endif
