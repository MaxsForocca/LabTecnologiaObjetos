#ifndef COUNTRY_H
#define COUNTRY_H

#include <QWidget>

namespace Ui {
class Country;
}

class Country : public QWidget
{
    Q_OBJECT

public:
    explicit Country(QWidget *parent = nullptr);
    ~Country();
    QString getCountry() const;
    QString getCapital() const;
    void setCountry(const QString &country);
    void setCapital(const QString &capital);
signals:
    void remove(Country* country);
public slots:
    void edit();
private:
    Ui::Country *ui;
};

#endif // COUNTRY_H
