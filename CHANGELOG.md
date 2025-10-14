# Changelog

All notable changes to the AlashIRControl library will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.7] - 2024-10-14

### Fixed
- Critical bug: Fixed assignment operator in protocol switching (line 40, changed `==` to `=`)
- This fixes the issue where protocol wasn't switching to IR_BIPHASIC when NRC check failed

### Added
- Multilingual README files (English, Russian, Kazakh)
- Main README.md with language navigation
- .gitignore file for Arduino development
- keywords.txt for Arduino IDE syntax highlighting
- CHANGELOG.md for tracking version history
- Comprehensive CLAUDE.md with architecture documentation

### Changed
- Reorganized examples into language-specific folders (en/, ru/, kk/)
- Each example folder now contains identical examples with translated comments
- Added README.md files in each language folder
- Updated CLAUDE.md with information about multilingual structure and known code issues

### Documentation
- Enhanced CLAUDE.md with:
  - Known code issues section
  - Multilingual examples structure
  - Development considerations
- Added parameter validation to critical functions:
  - NULL pointer checks in protocol functions
  - Length validation (1-32 bits) in send function
  - Frequency range validation (20-60 kHz) in send function

## [Earlier Versions]

### [1.0.6] and earlier
- Initial releases
- Basic IR receiver and transmitter functionality
- Protocol auto-detection
- Support for multiple IR encoding schemes (NEC, RC5, RC6, etc.)
- Platform support: AVR, ESP32, ESP8266, Arduino UNO R4

---

## Types of changes
- **Added** for new features
- **Changed** for changes in existing functionality
- **Deprecated** for soon-to-be removed features
- **Removed** for now removed features
- **Fixed** for any bug fixes
- **Security** in case of vulnerabilities
