#pragma once
#include <qfileinfo.h>
#include <qstring.h>
#include <qsettings.h>
#include <qdatetime.h>
#include <qdir.h>

class Utils {
public:
    static bool CheckFile(const QString& name)
    {
        QFileInfo fi(name);
        return fi.exists(name);
    }
};

class IniUtil {
public:
    ~IniUtil() {}
    IniUtil(const IniUtil&) = delete;
    IniUtil& operator=(const IniUtil&) = delete;
    static IniUtil& get_instance() {
        static IniUtil instance;
        return instance;
    }

private:
    IniUtil()
    {
    }

private:
    std::map<QString, QVariant> m_Inis;

    QString m_FileName;

public:
    bool LoadFile(const char* name)
    {
        if (Utils::CheckFile(name))
        {
            m_FileName = name;
            QSettings settins(name, QSettings::IniFormat);
            QStringList list = settins.allKeys();
            for (int i = 0; i < list.count(); i++)
            {
                QString key = list.at(i);
                QStringList _keys = key.split("/");
                QString _key = _keys.at(1);
                m_Inis.insert(std::make_pair(_key, settins.value(key)));
            }
            return true;
        }
        return false;
    }

    QVariant GetIniConfigQStr(QString key)
    {
        if(m_Inis.find(key)!=m_Inis.end())
            return m_Inis.at(key);
        return "";
    }

    void SetValue(QString key, QVariant value)
    {
        QSettings settins(m_FileName, QSettings::IniFormat);
        settins.setValue(key, value);
    }
};
