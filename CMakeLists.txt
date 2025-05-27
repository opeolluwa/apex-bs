cmake_minimum_required(VERSION 3.31)

project(banking_system)

include_directories(include lib)

add_executable(app main.c include/uuidv4.c lib/utils.c lib/transaction.c lib/bank.c lib/accounts.c)

