#include "addnewemailwindow.h"

AddNewEmailWindow::AddNewEmailWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");
    /*Layouts*/
    initLayouts();
    /*Validator*/
    initValidator();
    /*Ex buttons*/
    initExButtons();

}
void AddNewEmailWindow::StartHideAnim(){
    int left =0;
    int top =0;
    int height_ = height();
    int width_ = width();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width_, height_));
    animation->setEndValue(QRect(left, top, 1, height_));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(hide()));
    controllGroup->closeGroup();
    emit hide_();
}
void AddNewEmailWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    raise();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    controllGroup->moveToPoints(150 - controllGroup->getBigRadius()/2, this->height()-105);
    emit show_();
}
bool AddNewEmailWindow::isCorrectLineEdit(QLineEdit *lineEdit){
    if (lineEdit->text().isEmpty()){
        lineEdit->setStyleSheet("QLineEdit { border: 1px solid red}");
        return false;
    }
    else{
        lineEdit->setStyleSheet("");
        return true;
    }
}

void AddNewEmailWindow::onSaveAndExitEBClicked(){
    controllGroup->closeGroup();
    if (onCheckEmailEBClicked()){
        QString login, password;
        login = loginLE->text();
        password = passwordLE->text();
        tempAccount = new Account(login, password);
        tempAccount->setImapHost(imapHostLE->text());
        tempAccount->setImapPort(imapPortLE->text().toInt());
        tempAccount->setPop3Host(pop3hostLE->text());
        tempAccount->setPop3Port(pop3portLE->text().toInt());
        tempAccount->setSmtpHost(smtpHostLE->text());
        tempAccount->setSmtpPort(smtpPortLE->text().toInt());
        currentProfile->addNewEmail(tempAccount);

        QFile::remove(currentProfile->getSaveWay());
        currentProfile->saveprofile();

        StartHideAnim();
    }
}

void AddNewEmailWindow::onBackEBClicked(){
    controllGroup->closeGroup();
    StartHideAnim();
}

void AddNewEmailWindow::onDefaultEBClicked(){
    controllGroup->closeGroup();
}

void AddNewEmailWindow::onApproveEBClicked(){
    controllGroup->closeGroup();
}

bool AddNewEmailWindow::onCheckEmailEBClicked(){
    bool allOk=true;
    controllGroup->closeGroup();
    QString login;
    int pos=0;
    login= loginLE->text();

    allOk = isCorrectLineEdit(loginLE);
    allOk = isCorrectLineEdit(passwordLE);
    if (validator->validate(login, pos)!=2){
        loginLE->setStyleSheet("QLineEdit { border: 1px solid red}");
        return false;
    }
    /*
      m_validMailRegExp("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"),
      m_intermediateMailRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*")
    */
    /*
    QString login = it->GetLogin();
    QString pas = it->GetPassword();\
    QString host = it->GetPop3Host();
    int port = it->GetPop3PortEncr();

    Pop3 *temp = new Pop3(login, pas, host,port , QSsl::SslV3);
    temp->connectToHost();
    qDebug()<<it->GetPop3Host()<<"  "<<it->GetPop3PortEncr();
    if( temp->sendUser() ){
        qDebug()<<it->GetLogin()<<" login is correct";
        if (temp->sendPass()){
            qDebug()<<it->GetLogin()<<"pass is ok";
        }
        else{
            qDebug()<<it->GetLogin()<<"pass is not ok";
        }
    }
    else{
        qDebug()<<it->GetLogin()<<" login uncorect";
    }
    temp->sendQuit();
    delete temp;
    */
    return allOk;
}

void AddNewEmailWindow::setCurrentProfile(Profile *profile){
    currentProfile = profile;
    windowCaptionLabel->setText("Add new email: "+currentProfile->getLogin());
}

void AddNewEmailWindow::autoFillProtocol(){
    QString login;
    int pos=0;
    login= loginLE->text();
    if (validator->validate(login, pos)==2){
        QString domen;
        domen = login.right(login.length()-login.indexOf("@")-1);
        pop3hostLE->setText("pop."+domen);
        pop3portLE->setText("995");
        imapHostLE->setText("imap."+domen);
        imapPortLE->setText("993");
        smtpHostLE->setText("smtp."+domen);
        smtpPortLE->setText("465");
    }
}

void AddNewEmailWindow::setDefaults(){
    pop3hostLE->setText("");
    pop3portLE->setText("995");
    imapHostLE->setText("");
    imapPortLE->setText("993");
    smtpHostLE->setText("");
    smtpPortLE->setText("465");
    loginLE->setText("");
    passwordLE->setText("");
}

void AddNewEmailWindow::setDefaultSSLogin(){
    loginLE->setStyleSheet("");
}

void AddNewEmailWindow::setDefaultSSPassword(){
    passwordLE->setStyleSheet("");
}

void AddNewEmailWindow::initExButtons(){
    int margin = 10;
    int radius = 50;

    saveAndExitEB = new ExButton(this,  "Save", radius, 0);
    saveAndExitEB->move(800/4-100+50/2, 600/2+50/2+150);
    saveAndExitEB->setRotation(273);
    saveAndExitEB->setImage(":/resourses/icons/check_nb.png");
    saveAndExitEB->setImageMargin(margin);
    saveAndExitEB->setToolTip("Save email and exit setup.");

    backEB = new ExButton(this,  "Back", radius, 1);
    backEB->setImage(":/resourses/icons/back_nb.png");
    backEB->setImageMargin(margin);
    backEB->setToolTip("Exit without saving.");

    defaultEB = new ExButton(this,  "Restore", radius, 1);
    defaultEB->setImage(":/resourses/icons/restore_nb.png");
    defaultEB->setImageMargin(margin);
    defaultEB->setToolTip("Restore previous settings.");

    approveEB = new ExButton(this, "Approve", radius, 1);
    approveEB->setImage(":/resourses/icons/approve.png");
    approveEB->setImageMargin(margin);
    approveEB->setToolTip("Save email.");

    checkEmail = new ExButton(this,  "Check", radius, 1);
    checkEmail->setImage(":/resourses/icons/emailCheck_nb.png");
    checkEmail->setImageMargin(margin);
    checkEmail->setToolTip("Check email.");

    controllGroup= new GroupExButtons();

    controllGroup->addButton(saveAndExitEB);
    controllGroup->addButton(backEB);
    controllGroup->addButton(defaultEB);
    controllGroup->addButton(approveEB);
    controllGroup->addButton(checkEmail);

    controllGroup->setDefaultButton("Save");

    connect(saveAndExitEB, SIGNAL(leftClicked()), this, SLOT(onSaveAndExitEBClicked()));
    connect(backEB, SIGNAL(leftClicked()), this, SLOT(onBackEBClicked()));
    connect(defaultEB, SIGNAL(leftClicked()), this, SLOT(onDefaultEBClicked()));
    connect(approveEB, SIGNAL(leftClicked()), this, SLOT(onApproveEBClicked()));
    connect(checkEmail, SIGNAL(leftClicked()), this, SLOT(onCheckEmailEBClicked()));
}

void AddNewEmailWindow::initLayouts(){
    int margin = 0;
    int spacing = 0;

    mainLay= new QBoxLayout(QBoxLayout::TopToBottom);
    mainLay->setSpacing(spacing);
    mainLay->setMargin(margin);

    initCaptionLay();
    initEmailLay();
    initButtonLay();

    setLayout(mainLay);
}
void AddNewEmailWindow::initCaptionLay(){

    QWidget *labelCaptionBack = new QWidget();
    labelCaptionBack->setStyleSheet("background-color:rgba(250, 250, 250);border:0px; border-bottom: 1px solid lightgray");
    QBoxLayout *labelcaptionLay = new QBoxLayout(QBoxLayout::TopToBottom);
    labelCaptionBack->setMaximumHeight(32);
    labelCaptionBack->setMinimumHeight(32);
    labelcaptionLay->setSpacing(0);
    labelcaptionLay->setMargin(0);

    windowCaptionLabel = new QLabel("Add new email.");
    windowCaptionLabel->setStyleSheet("font: 14px; border:0px");

    labelcaptionLay->addWidget(windowCaptionLabel, 0, Qt::AlignCenter);
    labelCaptionBack->setLayout(labelcaptionLay);
    mainLay->addWidget(labelCaptionBack);
}

void AddNewEmailWindow::initButtonLay(){
    int margin = 0;
    int spacing = 0;
    buttonLay = new QBoxLayout(QBoxLayout::TopToBottom);
    buttonLay->setSpacing(spacing);
    buttonLay->setMargin(margin);
    buttonLay->addStretch(1);
    mainLay->addLayout(buttonLay);
}

void AddNewEmailWindow::initEmailLay(){
    int margin = 10;
    int spacing = 5;
    emailLay = new QBoxLayout(QBoxLayout::TopToBottom);
    emailLay->setSpacing(spacing);
    emailLay->setMargin(margin);
    QGroupBox *settingsGB = new QGroupBox("Email settings");
    QString styleSheetGB = "QLabel {border:0px} \
            QGroupBox{margin-top: 5px;} \
            QGroupBox::title {subcontrol-origin: margin; \
            subcontrol-position: top left;\
            left:10 px; bottom:2px}\
            QCheckBox{border: 0px}\
            QGroupBox::title {color: #8B6969}\
            QLineEdit{ border-style: solid;\
            border-width: 1px;\
            border-color: #BEBEBE;} \
            QLineEdit:hover{ border-style: solid;\
            border-width: 1px;\
            border-color: #8B8989;}\
            QLineEdit:focus{ border-style: solid;\
            border-width: 1px;\
            border-color: #4ea6ea;}\
            QLineEdit:disabled{ border-style: solid;\
            border-width: 1px;\
            border-color: #D3D3D3;}";

            settingsGB->setStyleSheet(styleSheetGB);

    emailLay->addWidget(settingsGB, 0);

    QGridLayout *innerLay = new QGridLayout(settingsGB);
    innerLay->setSpacing(spacing);
    innerLay->setMargin(margin);

    QLabel *loginL = new QLabel("Login");
    QLabel *passwordL = new QLabel("Password");
    loginLE = new QLineEdit();
    loginLE->setPlaceholderText("email@host.com");
    passwordLE = new QLineEdit();
    passwordLE->setEchoMode(QLineEdit::Password);
    passwordLE->setPlaceholderText("password");
    additionalSettings = new QCheckBox("Additional setup");
    additionalSettings->setChecked(false);

    innerLay->addWidget(loginL, 0, 0, Qt::AlignLeft);
    innerLay->addWidget(loginLE, 0, 1, Qt::AlignLeft);
    innerLay->addWidget(passwordL, 1, 0, Qt::AlignLeft);
    innerLay->addWidget(passwordLE, 1, 1, Qt::AlignLeft);
    QVBoxLayout * spacer = new QVBoxLayout;
    innerLay->addLayout(spacer, 2, 0, 1, 2);
    spacer->addSpacing(10);
    innerLay->addWidget(additionalSettings, 3,0,1,2,Qt::AlignLeft);

    QGroupBox *addSettingsGB = new QGroupBox("Additional settings");
    addSettingsGB->setStyleSheet(styleSheetGB);
    addSettingsGB->setEnabled(false);
    emailLay->addWidget(addSettingsGB, 0);
    QGridLayout *innerAddLay = new QGridLayout(addSettingsGB);
    innerAddLay->setSpacing(spacing);
    innerAddLay->setMargin(margin);
    QLabel *pop3hostL = new QLabel("POP3 host");
    QLabel *pop3portL = new QLabel("POP3 port");
    QLabel *imapHostL = new QLabel("IMAP host");
    QLabel *imapPortL = new QLabel("IMAP port");
    QLabel *smtpHostL = new QLabel("SMTP host");
    QLabel *smtpPortL = new QLabel("SMTP post");
    pop3hostLE = new QLineEdit();
    pop3portLE = new QLineEdit();
    imapHostLE = new QLineEdit();
    imapPortLE = new QLineEdit();
    smtpHostLE = new QLineEdit();
    smtpPortLE = new QLineEdit();

    innerAddLay->addWidget(pop3hostL, 0, 0, Qt::AlignLeft);
    innerAddLay->addWidget(pop3hostLE, 0, 1, Qt::AlignLeft);
    innerAddLay->addWidget(pop3portL, 1, 0, Qt::AlignLeft);
    innerAddLay->addWidget(pop3portLE, 1, 1, Qt::AlignLeft);
    innerAddLay->addWidget(imapHostL, 2, 0, Qt::AlignLeft);
    innerAddLay->addWidget(imapHostLE, 2, 1, Qt::AlignLeft);
    innerAddLay->addWidget(imapPortL, 3, 0, Qt::AlignLeft);
    innerAddLay->addWidget(imapPortLE, 3, 1, Qt::AlignLeft);
    innerAddLay->addWidget(smtpHostL, 4, 0, Qt::AlignLeft);
    innerAddLay->addWidget(smtpHostLE, 4, 1, Qt::AlignLeft);
    innerAddLay->addWidget(smtpPortL, 5, 0, Qt::AlignLeft);
    innerAddLay->addWidget(smtpPortLE, 5, 1, Qt::AlignLeft);

    mainLay->addLayout(emailLay);

    connect(additionalSettings, SIGNAL(toggled(bool)), addSettingsGB, SLOT(setEnabled(bool)));
    connect(loginLE, SIGNAL(returnPressed()), this, SLOT(autoFillProtocol()));
    connect(loginLE, SIGNAL(editingFinished()), this, SLOT(autoFillProtocol()));
    connect(loginLE, SIGNAL(textEdited(QString)), this, SLOT(setDefaultSSLogin()));
    connect(passwordLE, SIGNAL(textEdited(QString)), this, SLOT(setDefaultSSPassword()));
}

void AddNewEmailWindow::initValidator(){
    QRegExp mask("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}");
    validator = new QRegExpValidator(mask, 0);
    /*
    QValidator::Invalid         0	The string is clearly invalid.
    QValidator::Intermediate	1	The string is a plausible intermediate value.
    QValidator::Acceptable      2	The string is acceptable as a final result; i.e. it is valid.
    */
}
