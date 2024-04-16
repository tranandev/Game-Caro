﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    public partial class FormHistory : Form
    {
        public FormHistory(string list)
        {
            this.ControlBox = false;
            InitializeComponent();
            string[] historyList = list.Split('|');
            for (int i = 0; i < historyList.Length - 1; i++)
            {
                string[] childList = historyList[i].Split(',');
                string[] row = { "", childList[0], childList[1], childList[2], childList[3], childList[4], childList[5] };
                listHistory.Rows.Add(row);
            }
            listHistory.AllowUserToAddRows = false;
            listHistory.AllowUserToDeleteRows = false;
            listHistory.ReadOnly = true;
            if (listHistory.RowCount > 0) listHistory.FirstDisplayedScrollingRowIndex = listHistory.RowCount - 1;
            FormManager.openForm(Constants.FORM_MAIN);
        }

        private void listHistory_RowPostPaint(object sender, DataGridViewRowPostPaintEventArgs e)
        {
            listHistory.Rows[e.RowIndex].Cells[0].Value = (e.RowIndex + 1).ToString();
        }
    }
}
