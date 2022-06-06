#!/bin/bash
#cleans all files without any extension
ls | grep -v "\." | grep -v clean | xargs rm