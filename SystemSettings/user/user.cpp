#include "user.h"
#include "../systemsettings.h"
// Core
#include <QIcon>
#include <QSizePolicy>
#include <QWidget>
// UI
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QToolButton>
// Layout
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QDebug>

user::user(QWidget *parent, QStackedWidget *widget)
    : QWidget(parent), getWidget(widget) {

  // Label Variables
  QLabel *AppHeaderLabel = new QLabel;
  QLabel *ContentText = new QLabel;
  // Button Variables
  QToolButton *BackButton = new QToolButton;
  QPushButton *UserInfo = new QPushButton;
  QPushButton *AllUsers = new QPushButton;
  QPushButton *AllGroups = new QPushButton;

  // Layout Variables
  QHBoxLayout *AppHeaderLayout = new QHBoxLayout;
  QVBoxLayout *CategoryMenuLayout = new QVBoxLayout;
  QVBoxLayout *ContentLayout = new QVBoxLayout;
  QHBoxLayout *MainLayout = new QHBoxLayout;
  QVBoxLayout *AppLayout = new QVBoxLayout;

  // 1. App Header
  // 1.1 App Label
  AppHeaderLabel->setText("User Settings");
  AppHeaderLabel->setStyleSheet("font-size: 24px");
  AppHeaderLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  AppHeaderLabel->setFixedHeight(80);
  AppHeaderLabel->setMaximumHeight(80);

  // 1.2 Back Button
  BackButton->setText("Back");
  BackButton->setIcon(QIcon::fromTheme("arrow-left"));
  BackButton->setIconSize(QSize(32, 32));
  BackButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  BackButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  BackButton->setContentsMargins(20, 20, 20, 20);
  BackButton->setObjectName("BackButton");

  AppHeaderLayout->setContentsMargins(0, 0, 0, 0);
  AppHeaderLayout->addWidget(BackButton, Qt::AlignLeft, Qt::AlignVCenter);
  AppHeaderLayout->addStretch();
  AppHeaderLayout->addWidget(AppHeaderLabel);
  AppHeaderLayout->addStretch();

  // 2. Main Layout
  // 2.1 SubCategoryMenu
  UserInfo->setIcon(QIcon::fromTheme("user"));
  UserInfo->setIconSize(QSize(32, 32));
  UserInfo->setText("My Profile");
  UserInfo->setStyleSheet("text-align: left; padding: 2px; font-size: 12px; "
                          "background-color: none; boder: none;");
  UserInfo->setMaximumSize(200, 40);
  UserInfo->setMinimumSize(200, 40);

  AllUsers->setIcon(QIcon::fromTheme("group-users"));
  AllUsers->setIconSize(QSize(32, 32));
  AllUsers->setText("User Management");
  AllUsers->setStyleSheet("text-align: left; padding: 2px; font-size: 12px; "
                          "background-color: none; boder: none;");
  AllUsers->setMaximumSize(200, 40);
  AllUsers->setMinimumSize(200, 40);

  AllGroups->setIcon(QIcon::fromTheme("go-home"));
  AllGroups->setIconSize(QSize(32, 32));
  AllGroups->setText("Groups Management");
  AllGroups->setStyleSheet("text-align: left; padding: 2px; font-size: 12px; "
                           "background-color: none; boder: none;");
  AllGroups->setMaximumSize(200, 40);
  AllGroups->setMinimumSize(200, 40);

  CategoryMenuLayout->setSpacing(10);
  CategoryMenuLayout->addWidget(UserInfo);
  CategoryMenuLayout->addWidget(AllUsers);
  CategoryMenuLayout->addWidget(AllGroups);
  CategoryMenuLayout->addStretch();
  // 2.2 Content Area

  // Content
  ContentText->setText(
      "Main conentent\nMain conentent\nMain conentent\nMain conentent\n");

  // Content layout
  ContentLayout->addWidget(ContentText);
  ContentLayout->addStretch();

  // 3. Add Widgets to Mainlayout
  MainLayout->addItem(CategoryMenuLayout);
  MainLayout->addItem(ContentLayout);

  // 4. Create master layout
  AppLayout->addLayout(AppHeaderLayout);
  AppLayout->addLayout(MainLayout);

  connect(BackButton, &QPushButton::clicked,
          [this]() { getWidget->setCurrentIndex(0); });

  // 5. Set app layout
  setLayout(AppLayout);
}
