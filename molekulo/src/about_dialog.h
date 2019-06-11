/**********************************************************************
  Copyright (C) 2008-2014 Anton Simakov

  This file is part of Molekulo.
  For more information, see <http://code.google.com/p/molekulo/>

  Molekulo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Molekulo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Molekulo. If not, see <http://www.gnu.org/licenses/>.

 **********************************************************************/

#ifndef ABOUT_DIALOG_H
#define ABOUT_DIALOG_H

#include <memory>

#include <QDialog>

namespace molekulo
{
    class AboutDialog : public QDialog
    {
        Q_OBJECT

    public:
        AboutDialog(QWidget* parent = 0);
        ~AboutDialog();

        void setHeaderLabelText(const QString& text);

    private:
        struct AboutDialogPrivate;
        std::unique_ptr<AboutDialogPrivate> p;
    };
}

#endif // ABOUT_DIALOG_H
