#pragma once

#include <QMainWindow>

#include "settingsinfo.h"

namespace Ui {
class MainWindow;
}

class HttpServerHolder;
class MainWindow : public ExtendedMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionStartServer_triggered();

private slots:
    void on_actionExit_triggered();
    void on_actionSettings_triggered();
    void on_actionStopServer_triggered();
    void onMessage(const QString &_text, QtMsgType _type);

public:
    virtual void updateStyle() override;
    virtual void loadState(const LayoutSaver &_saver) override;
    virtual void saveState(LayoutSaver &_saver) const override;

protected:
    virtual void initUiComponets() override;
    virtual void initConnections() override;
    virtual void settingsChanged() override;

private:
    Ui::MainWindow *ui;
    TrayMenu *m_trayMenu = nullptr;
    HttpServerHolder *m_http = nullptr;
};



