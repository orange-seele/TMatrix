/*
 * Copyright (C) 2018-2026 Miloš Stojanović
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef MATRIX_CHAR_H
#define MATRIX_CHAR_H

#include <array>
#include "Active.h"
#include "CountdownTimer.h"
#include "HasTerminal.h"

class MatrixChar final : public Active, public HasTerminal {
	const unsigned x;
	const unsigned y;
	CountdownTimer UpdateTimer;
	size_t MCharIndex {GetRandomMCharIndex()};
	int ColorShade {0};

	static size_t GetRandomMCharIndex();
	void SetRandomMChar();
	void Draw() const;
	void Erase() const;
public:
	static constexpr std::size_t MCHAR_SIZE {sizeof("𐌇")-1};
	static constexpr std::size_t ALL_MCHARS_LENGTH {82};
	static constexpr std::array<const char [MCHAR_SIZE+1], ALL_MCHARS_LENGTH> ALL_MCHARS {
		"０", "１", "２", "３", "４", "５", "６", "７", "８", "９",
		"ア", "イ", "ウ", "エ", "オ", "カ", "キ", "ク", "ケ", "コ",
		"サ", "シ", "ス", "セ", "ソ", "タ", "チ", "ツ", "テ", "ト",
		"ナ", "ニ", "ヌ", "ネ", "ノ", "ハ", "ヒ", "フ", "ヘ", "ホ",
		"マ", "ミ", "ム", "メ", "モ", "ラ", "リ", "ル", "レ", "ロ",
		"ヤ", "ユ", "ヨ", "ワ", "ン", "ヲ", "Ｈ", "Ｚ", "Ｅ", "Ｉ",
		"Ｎ", "Ｘ", "＝", "＋", "〜", "＊", "－", "／", "＞", "＜",
		"：", "．", "・", "；", "＄", "＠", "％", "＆", "日", "？",
		"　", "＃"
	};
	static constexpr char EMPTY_MCHAR[MCHAR_SIZE+1] {" "};

	MatrixChar(unsigned X, unsigned Y, int UpdateRate, int UpdateTime) : x{X}, y{Y},
		UpdateTimer{UpdateRate, UpdateTime} {
		Draw();
	}
	~MatrixChar() {
		Erase();
	}

	static const char *GetMChar(std::size_t index)
	{
		return ALL_MCHARS[index];
	}

	static const char *GetEmptyMChar()
	{
		return ALL_MCHARS[ALL_MCHARS_LENGTH-2];
	}

	unsigned GetVerticalOffset(unsigned verticalPosition) {
		return verticalPosition - y;
	}

	void Update() final;
	void SetColorShade(int colorShade);
};

#endif
