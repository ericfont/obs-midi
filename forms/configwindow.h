#pragma once
#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H


//include obs stuff
#include <obs.hpp>
#include <obs-module.h>

//qt stuff
#include <QDialog>
#include <QTableView>
//#include <QMainWindow>
#include <QAbstractTableModel>
#include <QWidget>
#include "ui_configwindow.h"
//#include "midi-agent.h"
//#include "midi-agent.h"
class QComboBox;
class QDataWidgetMapper;
class QLabel;
class QLineEdit;
class QPushButton;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
class QAbstractItemView;




class ConfigWindow : public QDialog{
		Q_OBJECT
	 public:
    explicit ConfigWindow(std::string devicename);
    ~ConfigWindow();
    void SetupModel();
    void on_btn_back_clicked();
    void rebuildModel();
    void ToggleShowHide();
    void TselChanged(QModelIndex i);
    
    //variables
    std::string devicename;
    QTableView tableEntity;
    void loadFromHooks();
	//MakeCombos
    void AddRowFromHooks(int row, std::string mtype, int mindex, bool bid,
			 std::string atype, std::string action,
			 std::string option1, std::string option2,
			 std::string option3);
    bool inrow(int x);
    bool inrow(int x, QString mtype);
    bool dirty;

private slots:

	void load();
	
	void addrow();
	void deleterow();
	void setDirty() { setWindowModified(true); }
	void updateUi();
	void selectionChanged();
	void domessage(QString name, QString mtype, int mchan);
	void insertRow(QString mtype, int mindex);
	void select(int row, int col);
	void sendToTable();
	void save();
	void chooseOptions1(QString Action);
	void MakeSceneCombo();
	void MakeVolumeCombo();
	//Combobox Actions
	void chooseAtype(QString index);
	void clearTable();
    private:
	QStringList ScenesList ;
	QStringList VolumeList;

	
	QStringList ButtonAList = {"Set Current Scene",
				    "Set Preview Scene",
				    "Toggle Mute",
				    "Set Mute",
				    "Start Stop Streaming",
				    "Start Streaming",
				    "Stop Streaming",
				    "Start Stop Recording",
				    "Start Recording",
				    "Stop Recording",
				    "Start Stop Replay Buffer",
				    "Start Replay Buffer",
				    "Stop Replay Buffer",
				    "Save Replay Buffer",
				    "Pause Recording",
				    "Resume Recording",
};
	QStringList ButtonTodo = {
		"Transition To Program",        "Set Current Transition",
		"Set Source Visibility",        "Toggle Source Visibility",
		"Set Transition Duration",      "Set Current Profile",
		"Set Current Scene Collection", "Reset Scene Item",
		"Set Text GDIPlus Text",        "Set Browser Source URL",
		"Reload Browser Source",        "Take Source Screenshot",
		"Enable Source Filter",         "Disable Source Filter",
		"Toggle Source Filter"

	};
	QStringList FaderTodo = {
		"Set Sync Offset",         "Set Source Position",
		"Set Source Rotation",     "Set Source Scale",
		"Set Transition Duration", "Set Gain Filter"};
	QStringList FaderAList = {"Set Volume",
		};

	


	QStringListModel *options1model;
	QStringListModel *options2model;
	QStringListModel *options3model;

	


	
	Ui::ConfigWindow ui;
	//std::vector<MidiHook *> hooks;

};

#endif // CONFIGWINDOW_H