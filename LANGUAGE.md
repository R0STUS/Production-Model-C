# ENGLISH


# Neural Language (AI)
## NL(AI)

## Hello, World!
```nlai
printTest
Hello, World!
end
```

Let's break it down line by line:
```nlai
printTest
```
This means that all subsequent records are outputs to the console.
```nlai
Hello, World!
```
This is the actual Hello, World!
```nlai
end
```
This means that we no longer output subsequent records to the console.

## Functions:
```nlai
printDebug
This is debug message.
end
```
Output:
```shell
  DEBUG: This is debug message.
```
```nlai
printDebugInfo
This is debug info message.
end
```
Output:
```shell
  INFO: This is debug info message.
```

```nlai
printDebugWarn
This is debug warning message.
end
```
Output:
```shell
  WARNING: This is debug warning message.
```

```nlai
printDebugErr
This is debug error message.
end
```
Output:
```shell
  ERROR! This is debug error message.
```

```nlai
getRequest
```
Requests a request from the user to the neural network.

```nlai
getWeights
```
Gets the weight and bias for a token from a file.

```nlai
clearRequest
```
Clears the request variable.

```nlai
noDebug
true/false
end
```
Prohibits/allows the output of debug messages.
Output:
```shell
No Debug = true/false
```

```nlai
cmd
sh/bat command (In Linux uses sh, in Windows uses bat)
end
```
Executes terminal commands.

```nlai
check
res/file.nlai
src/file.cpp
catchErr
Error message.
error
end
```
Checks files for openability. Otherwise, it calls catchErr. In catchErr, you can optionally call error, which will interrupt the execution of the process.
Output, if the files didn't open:
```shell
  ERROR! Error message.
  ERROR! An 'error' called in file 'file.nlai' at line 6.
```

```nlai
function
res/function.nlai
end
```
Executes the code in the file specified in the path. The path is specified from the place where the interpreter was called.
If the code in the file function.nlai:
```nlai
printTest
File is opened.
end
```
Then the output:
```nlai
File is opened.
```

```nlai
leave
```
Interrupts the execution of the code without an error. (With code 0)
Output:
```shell
  INFO: An 'leave' called in file 'file.nlai' at line 1.
```

```nlai
error
```
Interrupts the execution of the code with an error. (With code 1)
Output:
```shell
  ERROR! An 'error' called in file 'file.nlai' at line 1.
```

## Functions in 'settings.nlai':
```nlai
MAINFILE
res/file.nlai
end
```
Sets the file that will be interpreted first.
Output:
```shell
  Main File = res/file.nlai
```

```nlai
printTest
Hello, World!
end
```
This is output to the console.

```nlai
noDebug
true/false
end
```
Prohibits/allows the output of debug messages.
Output:
```shell
No Debug = true/false
```

The end.




# RUSSIAN


# Нейронный Язык (ИИ)
## NL(AI)
## (англ. - Neural Language (AI))



## Hello, World!
```nlai
printTest
Hello, World!
end
```

Разберём построчно:
```nlai
printTest
```
Это означает, что все последующие записи - выводы в консоль.

```nlai
Hello, World!
```
Это, собственно, сам Hello, World!

```nlai
end
```
Это означает, что мы больше не выводим в консоль последующие записи.

## Функции:
```nlai
printDebug
This is debug message.
end
```
Вывод:
```shell
  DEBUG: This is debug message.
```

```nlai
printDebugInfo
This is debug info message.
end
```
Вывод:
```shell
  INFO: This is debug info message.
```

```nlai
printDebugWarn
This is debug warning message.
end
```
Вывод:
```shell
  WARNING: This is debug warning message.
```

```nlai
printDebugErr
This is debug error message.
end
```
Вывод:
```shell
  ERROR! This is debug error message.
```

```nlai
getRequest
```
Запрашивает у пользователя запрос к нейросети.

```nlai
getWeights
```
Получает вес и смещение для токена из файла.

```nlai
clearRequest
```
Очищает переменную request.

```nlai
noDebug
true/false
end
```
Запрещает/разрешает вывод debug-сообщений.
Вывод:
```shell
No Debug = true/false
```

```nlai
cmd
sh/bat command (На Linux используется sh, на Windows используется bat)
end
```
Выполняет команды терминала.

```nlai
check
res/file.nlai
src/file.cpp
catchErr
Error message.
error
end
```
Проверяет файлы на открываемость. В противном случае вызывает catchErr. В catchErr, по желанию, можно вызвать error, который прервёт выполнение процесса.
Вывод, если файлы не открылись:
```shell
  ERROR! Error message.
  ERROR! An 'error' called in file 'file.nlai' at line 6.
```

```nlai
function
res/function.nlai
end
```
Выполняет код в файле, указанном в пути. Путь указывается из того места, где был вызван интерпретатор.
Если код в файле function.nlai:
```nlai
printTest
File is opened.
end
```
То вывод:
```shell
File is opened.
```

```nlai
leave
```
Прерывает выполнение кода без ошибки. (С кодом 0)
Вывод:
```shell
  INFO: An 'leave' called in file 'file.nlai' at line 1.
```

```nlai
error
```
Прерывает выполнение кода с ошибкой. (С кодом 1)
Вывод:
```shell
  ERROR! An 'error' called in file 'file.nlai' at line 1.
```

## Функции 'settings.nlai':

```nlai
MAINFILE
res/file.nlai
end
```
Задаёт файл, который будет интерпретироваться в первую очередь.
Вывод:
```shell
  Main File = res/file.nlai
```

```nlai
printTest
Hello, World!
end
```
Это вывод в консоль.

```nlai
noDebug
true/false
end
```
Запрещает/разрешает вывод debug-сообщений.
Вывод:
```shell
No Debug = true/false
```

Конец.