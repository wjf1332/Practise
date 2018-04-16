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

- log
    > 查看历史提交信息(是从当前HEAD开始算起)
    - --pretty=oneline
        > 一行显示
- reflog
    > git reflog 查看命令历史，以便确定要回到未来的哪个版本
- reset 
    > 回退到上一个版本
    > 格式：git reset --hard HEAD^ 表示上一个版本，HEAD^^是上上个版本，HEAD~100是上100个版本 ？(我测试的时候，为什么会出现More？)

    

