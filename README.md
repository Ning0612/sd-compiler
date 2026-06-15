
---

# 🛠️ sD Compiler – Project 3

本專案實作一個自訂 C-like 教學語言 **sD** 的完整編譯器，涵蓋 **語彙分析**、**語法分析**、**語意分析** 與 **程式碼產生（Code Generation）**。產生的目標碼為 Java Assembly Language，並透過 `javaa` 工具轉譯為 JVM 可執行的 `.class` 檔。

---

## 📁 專案結構

```
.
├── Makefile               # 編譯與測試腳本
├── bin/sd                 # 編譯器執行檔
├── build/                 # 中間產物與物件檔
├── src/                   # 原始碼：scanner、parser、semantic analyzer、codegen
├── input/                 # 測試檔案（.sd）
│   ├── case1.sd           # 浮點運算與比較
│   ├── case2.sd           # 字串串接範例
│   ├── case3.sd           # if-else if-else 結構
│   ├── case4.sd           # foreach 變數範例
│   ├── case5.sd           # 印出前 30 個質數
│   ├── case6.sd           # do-while 迴圈範例
```

---

## 🔧 編譯與執行方式

### 編譯整體專案

```bash
make
```

### 執行編譯器並產生 Java Assembly

```bash
./bin/sd input/case1.sd
```

此動作會產生 `case1.j`，接著可用 Java Assembler 組譯並執行：

```bash
./javaa case1.j
java case1
```

或使用快捷方式：

```bash
make test-java TEST=case1
```

---

## ✅ 支援的語言功能

### 基本型別

* `int`, `float`
* `bool`, `const string`

### 敘述（Statements）

* 宣告與初始化 (`const` / `var`)
* 控制結構：`if`、`if-else`、`while`、`do-while`、`for`、`foreach`
* 輸出：`print`、`println`
* `return`

### 運算式（Expressions）

* 算術運算：`+`, `-`, `*`, `/`, `%`
* 邏輯運算：`!`, `&&`, `||`
* 比較運算：`<`, `>`, `<=`, `>=`, `==`, `!=`
* 字串常數串接：`"a" + "b"`
* 常數摺疊（Constant Folding）

### 函式

* 傳回值與參數型別檢查
* 參數傳遞與函式呼叫驗證
* 回傳整數或無傳回值（`void`）

---

## ⚙️ Code Generation（Java Assembly）

生成 `.j` 檔案為 JVM 的中介語言，經 `javaa` 組譯器轉換為可執行的 `.class`。

### 限制

* 不支援 、陣列、`read` 敘述
* 字串僅可用於 `print/println`，不支援字串變數
* 不支援字串指定與運算

### 對應映射（部分）

| sD 語法       | JVM Assembly                                      |
| ----------- | ------------------------------------------------- |
| `a = 5`     | `sipush 5` + `putstatic int example.a`            |
| `b = a + 1` | `getstatic` + `sipush` + `iadd` + `istore`        |
| `if` 條件判斷   | `isub` + `iflt` 等條件跳躍指令                           |
| `print` 字串  | `ldc "str"` + `invokevirtual println(...)`        |
| `function`  | `method public static ...` + `ireturn` 或 `return` |
| `call`      | `invokestatic` 呼叫靜態函式                             |

---

## 🧪 測資說明

所有測試檔案位於 input/ 目錄下，每個 .sd 程式測試特定語意功能與 Code Generation 行為：

| 檔名         | 測試內容說明                             |
| ---------- | ---------------------------------- |
| `case1.sd` | 測試整數四則運算與比較運算（包含常數摺疊）              |
| `case2.sd` | 字串常數與串接測試、`print` 與 `println` 敘述   |
| `case3.sd` | 多層次條件分支（`if - else if - else`）控制流程 |
| `case4.sd` | 測試 `foreach` 語法與變數作用域規則            |
| `case5.sd` | 印出前 30 個質數，測試 `while`、布林邏輯與條件跳躍    |
| `case6.sd` | `do-while` 迴圈結構與布林判斷的產碼            |
| `case7.sd` | 自訂函式呼叫與遞迴測試（例如費氏數列）                |
| `case8.sd` | 綜合測試：變數宣告、運算、控制流程與函式調用             |


---

## 📄 執行流程範例

以下以 `case1.sd` 為例：

1. 編譯 `.sd` 檔：

   ```bash
   ./bin/sd input/case1.sd
   ```

2. 產出 `case1.j` Java Assembly 檔

3. 使用 `javaa` 組譯並執行：

   ```bash
   ./javaa case1.j
   java case1
   ```

---

## 📦 Repository

```bash
git clone https://github.com/Ning0612/sd-compiler.git
cd sd-compiler
```

---

## ✍️ 作者與課程資訊

本專案為國立臺灣科技大學 資訊工程系「Compiler Project 3」課程作業
作者：B11110524 / Ning
學期：春季班 2025

---
