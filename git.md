## 
- config --global user.name "Your Name" 
- config --global user.email "email@example.com"
    > --global表示本机器所有的仓库都使用该配置
- init
    > 仓库初始化（会在当前目录下创建.git目录，用来跟踪版本库）
## 
- add
    > 提交修改/新文件
- status
    > 查看当前仓库的状态
- diff
    > (可以在提交前)查看当前修改的内容
    > git diff HEAD -- *.* 用来查看工作区和版本库里最新版的区别

- log
    > 查看历史提交信息(是从当前HEAD开始算起)
    - --pretty=oneline
        > 一行显示
- reflog
    > git reflog 查看命令历史，以便确定要回到未来的哪个版本
- reset 
    > 回退到上一个版本
    > 格式：git reset --hard HEAD^ 表示上一个版本，HEAD^^是上上个版本，HEAD~100是上100个版本 ？(我测试的时候，为什么会出现More？)

- checkout 
    - -- file
        > 其中--命令必须有，否则就会成为“切换另一个分支”了
        >
        >1.当工作区被乱改，想丢弃，则直接checkout -- file即可。
        >
        >2.若乱改后且已经添加到暂存区，reset HEAD file,可以回到场景1，然后按1操作
        >
        >3.若已经提交， 则可以考虑版本回退（当然了，你若已经提交到了远程库，则某些不合适的修改必然可以被大伙看到，且没法撤销了）
- rm
    > 删除文件
    


