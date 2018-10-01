TEMPLATE = subdirs

SUBDIRS = Common Client Server

Client.depends = Common
Server.depends = Common

CONFIG += ordered
