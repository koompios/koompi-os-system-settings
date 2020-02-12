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

  // Button Variables
  QToolButton *BackButton = new QToolButton;
  QPushButton *UserInfoButton = new QPushButton;
  QPushButton *AllUsersButton = new QPushButton;
  QPushButton *AllGroupsButton = new QPushButton;

  // Layout Variables
  QHBoxLayout *AppHeaderLayout = new QHBoxLayout;
  QVBoxLayout *SubMenuLayout = new QVBoxLayout;
  QVBoxLayout *ContentLayout = new QVBoxLayout;
  QHBoxLayout *MainLayout = new QHBoxLayout;
  QVBoxLayout *AppLayout = new QVBoxLayout;
  QScrollArea *MainArea = new QScrollArea;

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
  user::SubMenuButton(UserInfoButton, "My Profile", "user");
  user::SubMenuButton(AllUsersButton, "User Management", "group-users");
  user::SubMenuButton(AllGroupsButton, "Group Management", "go-home");

  SubMenuLayout->setSpacing(10);
  SubMenuLayout->addWidget(UserInfoButton);
  SubMenuLayout->addWidget(AllUsersButton);
  SubMenuLayout->addWidget(AllGroupsButton);
  SubMenuLayout->addStretch();
  // 2.2 Content Area
  QLabel *UserName = new QLabel;
  QString name = qgetenv("USER");
  UserName->setText(name.toUpper());

  MainArea->setWidget(UserName);
  ContentLayout->addWidget(MainArea);

  // 3. Add Widgets to Mainlayout
  MainLayout->addItem(SubMenuLayout);
  MainLayout->addItem(ContentLayout);

  // 4. Create master layout
  AppLayout->addLayout(AppHeaderLayout);
  AppLayout->addLayout(MainLayout);

  connect(BackButton, &QPushButton::clicked,
          [this]() { getWidget->setCurrentIndex(0); });

  // 5. Set app layout
  setLayout(AppLayout);
}

QPushButton *user::SubMenuButton(QPushButton *button, QString name,
                                 QString icon) {
  button->setIcon(QIcon::fromTheme(icon));
  button->setIconSize(QSize(32, 32));
  button->setText(name);
  button->setStyleSheet("text-align: left; padding: 2px; font-size: 12px; "
                        "background-color: none;");
  button->setMaximumSize(200, 40);
  button->setMinimumSize(200, 40);

  return button;
}
