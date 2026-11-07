# Encoding
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8

# Modules (fail soft so a missing dependency doesn't break the shell)
foreach ($module in @('Terminal-Icons', 'PSReadLine')) {
    try {
        Import-Module -Name $module -ErrorAction Stop
    }
    catch {
        Write-Warning "Could not import module '$module': $_"
    }
}

# PSReadLine
if (Get-Module -Name PSReadLine) {
    Set-PSReadLineOption -EditMode Emacs
    Set-PSReadLineOption -PredictionSource History
    Set-PSReadLineOption -PredictionViewStyle ListView
    Set-PSReadLineOption -HistorySearchCursorMovesToEnd
    Set-PSReadLineOption -HistoryNoDuplicates
    Set-PSReadLineOption -MaximumHistoryCount 10000
    Set-PSReadLineOption -BellStyle None

    Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
    Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward
    Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete
}

# Oh My Posh — resolve theme next to this profile, with a $HOME fallback
$ompTheme = Join-Path $PSScriptRoot 'elantris.omp.json'
if (-not (Test-Path -LiteralPath $ompTheme)) {
    $ompTheme = Join-Path $HOME 'elantris.omp.json'
}
if ((Get-Command oh-my-posh -ErrorAction SilentlyContinue) -and (Test-Path -LiteralPath $ompTheme)) {
    oh-my-posh init pwsh --config $ompTheme | Invoke-Expression
}
else {
    Write-Warning "oh-my-posh or theme not found; skipping prompt init."
}

# Shortcuts
function gs { git status @args }
function gd { git diff @args }
function gco { git checkout @args }

# Native completions
Register-ArgumentCompleter -Native -CommandName dotnet -ScriptBlock {
    param($commandName, $wordToComplete, $cursorPosition)
    dotnet complete --position $cursorPosition "$wordToComplete" | ForEach-Object {
        [System.Management.Automation.CompletionResult]::new($_, $_, 'ParameterValue', $_)
    }
}
