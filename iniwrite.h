#ifndef INIWRITE_H
#define INIWRITE_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class IniWrite;
}

class IniWrite : public QWidget
{
    Q_OBJECT

public:
    explicit IniWrite(QWidget *parent = nullptr);
    ~IniWrite();

private:
    QSettings *iniFile;

    void writeConfig();

    void readConfig();

    Ui::IniWrite *ui;
};

#endif // INIWRITE_H
