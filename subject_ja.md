# C++ - Module 01

## メモリ割り当て、メンバーポインタ、参照、およびswitch文

### 概要:

このドキュメントには、C++ モジュールの Module 01 の演習が含まれています。

バージョン: 10.1

---

## 目次

1. [はじめに](#chapter-i)
2. [一般的なルール](#chapter-ii)
3. [演習00: BraiiiiiiinnnzzzZ](#chapter-iii)
4. [演習01: Moar brainz!](#chapter-iv)
5. [演習02: HI THIS IS BRAIN](#chapter-v)
6. [演習03: Unnecessary violence](#chapter-vi)
7. [演習04: Sed is for losers](#chapter-vii)
8. [演習05: Harl 2.0](#chapter-viii)
9. [演習06: Harl filter](#chapter-ix)
10. [提出と相互評価](#chapter-x)

---

## <a name="chapter-i"></a>Chapter I - はじめに

C++ は、Bjarne Stroustrup によって C 言語を拡張する形で作られた汎用プログラミング言語です。

このモジュールの目的は、オブジェクト指向プログラミング（OOP）を紹介することです。C++ は C の派生言語であり、OOP を学ぶのに適した選択です。このモジュールでは C++98 標準に準拠する必要があります。

現代の C++ は大きく異なりますが、上達のためには自分自身でさらに学ぶことが求められます。

---

## <a name="chapter-ii"></a>Chapter II - 一般的なルール

### コンパイル

* `-Wall -Wextra -Werror` フラグ付きで `c++` でコンパイル。
* `-std=c++98` フラグを追加してもコンパイル可能であること。

### フォーマットと命名規則

* ディレクトリ名: ex00, ex01, ..., exn
* ファイル、クラス、関数などは指示通りに命名。
* クラス名は UpperCamelCase。
* クラスを含むファイル名はそのクラス名に準ずる。
* 出力は必ず改行文字で終わり、標準出力に表示すること。
* Norminette は使用しないが、読みやすいコードを書くこと。

### 使用可能/禁止事項

* C++ 標準ライブラリの使用は基本的に許可。
* 外部ライブラリ（C++11、Boostなど）は禁止。
* `*printf()`, `*alloc()`, `free()` は使用禁止。
* `using namespace` と `friend` は明示的に許可されていない限り禁止。
* Module 08, 09 までは STL の使用禁止。

### 設計要件

* メモリリークを避けること。
* Module 02 以降のクラスは Orthodox Canonical Form であること。
* 実装をヘッダに書く場合（テンプレート以外）は減点。
* 各ヘッダは他のヘッダに依存しない形で独立している必要あり。
* include guard を忘れずに。

### その他の注意

* コード分割用に追加ファイルを作成可。
* 仕様は簡潔でも例で暗黙の要件が示されていることがある。
* モジュール全体を最初に読むこと。
* Makefile のルールは C のルールに準拠。

---

## <a name="chapter-iii"></a>Chapter III - Exercise 00: BraiiiiiiinnnzzzZ

### 内容:

Zombie クラスを実装。

* メンバ: `std::string name`
* メンバ関数: `void announce(void)`

出力:

```
<name>: BraiiiiiiinnnzzzZ...
```

関数:

* `Zombie* newZombie(std::string name);`
* `void randomChump(std::string name);`

Zombie の生成をヒープとスタックで使い分ける意図を理解すること。
Zombie が破棄されるとき、デストラクタが名前付きのデバッグメッセージを表示すること。

---

## <a name="chapter-iv"></a>Chapter IV - Exercise 01: Moar brainz!

### 内容:

複数の Zombie を一括で生成。
関数:

```cpp
Zombie* zombieHorde(int N, std::string name);
```

* N体の Zombie を動的に一括生成。
* 各Zombieに同じ名前を設定。
* 各Zombieに `announce()` を呼び出す。
* 必ず `delete[]` で解放し、メモリリークを確認すること。

---

## <a name="chapter-v"></a>Chapter V - Exercise 02: HI THIS IS BRAIN

### 内容:

* `std::string` を初期化
* `stringPTR`: ポインタ
* `stringREF`: 参照

出力:

* それぞれのメモリアドレス
* 各変数の値

参照に慣れるための練習。

---

## <a name="chapter-vi"></a>Chapter VI - Exercise 03: Unnecessary violence

### 内容:

* `Weapon` クラス

    * 属性: `std::string type`
    * 関数: `getType()`, `setType()`

* `HumanA`, `HumanB` クラス

    * 名前と武器を持つ
    * 関数: `attack()`

違い:

* `HumanA`: 武器をコンストラクタで受け取る、常に武器を持つ
* `HumanB`: 武器は任意、後から `setWeapon()` で設定

攻撃時:

```
<name> attacks with their <weapon type>
```

* `setType()` を用いた型変更時の反映を確認。
* メモリリークの確認を忘れずに。

---

## <a name="chapter-vii"></a>Chapter VII - Exercise 04: Sed is for losers

### 内容:

引数:

* `filename`, `s1`, `s2`

処理:

* ファイル `<filename>` を読み取り、`<filename>.replace` に内容をコピー。
* 文字列 `s1` をすべて `s2` に置換。

制限:

* Cファイル操作は禁止
* `std::string::replace` 使用禁止
* その他のメンバ関数使用可

---

## <a name="chapter-viii"></a>Chapter VIII - Exercise 05: Harl 2.0

### 内容:

* `Harl` クラス
* private関数: `debug()`, `info()`, `warning()`, `error()`
* 公開関数: `complain(std::string level)`

条件:

* if/else の連鎖は禁止
* メンバ関数ポインタを使用すること

例のようなメッセージを出力:

* DEBUG, INFO, WARNING, ERROR に対応

---

## <a name="chapter-ix"></a>Chapter IX - Exercise 06: Harl filter

### 内容:

* 引数でログレベルを受け取り、それ以上のレベルのメッセージを表示。
* 無効なレベルにはプレースホルダメッセージを表示。

出力例:

```
$> ./harlFilter "WARNING"
[ WARNING ]
...
[ ERROR ]
...
```

* `switch` 文を使用すること
* 実装は任意だが、やると学習効果が高い

---

## <a name="chapter-x"></a>Chapter X - 提出と相互評価

* Git リポジトリに提出。
* 評価時には提出済みのファイルのみ対象。
* ディレクトリやファイル名の確認を徹底すること。

---
