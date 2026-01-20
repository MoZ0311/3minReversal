// MessageWindow class

#pragma once

class MessageWindow
{
public:

	// コンストラクタ
	MessageWindow();

	// 更新処理
	void update();

	// 描画処理
	void draw() const;

	// 読み込むCSVファイルの設定
	void setCSV(const FilePath& path);

	// CSVファイルを読み終えたか
	bool completedCSV;

private:

	// ページ送り/全文表示の処理
	void getNextMessage();

	const RoundRect m_textWindow;

	// 読み込むCSVファイル
	CSV m_csv;

	// 読み込む行のインデックス
	int32 m_rowIndex;

	// 表示する文字列
	String m_messageText;

	// 表示する文字列の長さ
	double m_displayTextLength;

	// 全文を表示し終えたか
	bool m_finishSentence;
};
